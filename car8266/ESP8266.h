//Classe costruita dal Prof. Fabrizio Tamigi nell'ambito delle attività di laboratorio scolastico


#define DEFAULT_BAUD 115200
#define DEF_TIMEOUT_RX 9
#define BAUD_TABLE 9600, 14400, 19200, 28800, 38400, 57600, 115200, 128000, \
	230400, 250000, 256000, 460800, 500000, 512000, 921600, 1000000, 1024000
#define BAUD_TABLE_LEN 17
#define REPLY_TIMEOUT 1000
#define RST_DELAY 500
#define TX_BUF_SIZE 1024

//#define TOKEN_RX "+IPD,"
//#define ACTIV_LED_PIN 13

class ESP8266 {

private:

	unsigned long _baud = DEFAULT_BAUD;
	unsigned int _timeout_rx = DEF_TIMEOUT_RX;

	bool available(unsigned long timeout) {
		unsigned long start = millis();
		while (millis() - start < timeout)
			if (Serial.available() > 0)
				return true;
		return false;
	}

	String read(unsigned long timeout) {
		String buffer = "";
		unsigned long start = millis();
		while (millis() - start < timeout)
			if (Serial.available() > 0)
				buffer += (char)Serial.read();
		return buffer;
	}

	bool wait(String pattern, unsigned long timeout) {
		String buffer = "";
		unsigned long start = millis();
		while (millis() - start < timeout)
			if (Serial.available() > 0) {
				buffer += (char)Serial.read();
				if (pattern.length() > 0 && buffer.indexOf(pattern) != -1)
					return true;
			}
		return false;
	}

	void flush(unsigned long timeout) {
		while (available(timeout))
			Serial.read();
	}

public:

	bool baud(unsigned long baud_rate = 0) {
		const static unsigned long baud[BAUD_TABLE_LEN] PROGMEM = { BAUD_TABLE };
		for (int i = 0; i < BAUD_TABLE_LEN; i++) {
			unsigned long baud_cur = pgm_read_dword(baud + i);
			if (baud_rate == baud_cur) {
				Serial.print(F("AT+UART_CUR="));
				Serial.print((String)baud_cur);
				Serial.println(F(",8,1,0,0"));
//				delay(50);
				flush(50);
			}
			else if (baud_rate != 0)
				continue;
			Serial.begin(baud_cur);
			Serial.println(F("AT"));
			if (wait("OK", REPLY_TIMEOUT)) {
				_baud = baud_cur;
				_timeout_rx = 10E6 / baud_cur;// +1;
				return true;
			}
		}
		_baud = DEFAULT_BAUD;
		_timeout_rx = DEF_TIMEOUT_RX;
		Serial.begin(_baud);
		return false;
	}

	bool reset() {
		Serial.println(F("AT+RST"));
		if (!wait("OK", REPLY_TIMEOUT))
			return false;
		delay(RST_DELAY);
		Serial.println(F("ATE0"));
		return wait("OK", REPLY_TIMEOUT);
	}

	bool init(String ssid, String ip, unsigned int port) {
		Serial.println(F("AT+CWMODE_CUR=2"));
		if (!wait("OK", REPLY_TIMEOUT))
			return false;
		Serial.print(F("AT+CWSAP_CUR=\""));
		Serial.print(ssid);
		Serial.println(F("\",,5,0"));
		if (!wait("OK", REPLY_TIMEOUT))
			return false;
		Serial.print(F("AT+CIPAP_CUR=\""));
		Serial.print(ip);
		Serial.println(F("\""));
		if (!wait("OK", REPLY_TIMEOUT))
			return false;
		Serial.println(F("AT+CWDHCP_CUR=0,1"));
		if (!wait("OK", REPLY_TIMEOUT))
			return false;
		Serial.println(F("AT+CIPMODE=0"));
		if (!wait("OK", REPLY_TIMEOUT))
			return false;
		Serial.println(F("AT+CIPMUX=1"));
		if (!wait("OK", REPLY_TIMEOUT))
			return false;
		Serial.print(F("AT+CIPSERVER=1,"));
		Serial.println(port);
		return wait("OK", REPLY_TIMEOUT);
	}

	bool stop(byte link) {
		Serial.print(F("AT+CIPCLOSE="));
		Serial.println((String)link);
		return wait("OK", REPLY_TIMEOUT);
	}

	String receive(int &link) {
		link = -1;
		String buffer = read(_timeout_rx);
		int token_pos = buffer.indexOf(F("+IPD,"));
		if (token_pos != -1) {
			link = buffer.substring(token_pos + 5, token_pos + 6).toInt();
			int sep_pos = buffer.indexOf(':', token_pos + 6);
			if (sep_pos != -1)
				return buffer.substring(sep_pos + 1);
		}
		return "";
	}

	bool send(String buffer, byte link) {
		Serial.print(F("AT+CIPSEND="));
		Serial.println((String)link + "," + (String)buffer.length());
		if (wait(">", REPLY_TIMEOUT)) {
			Serial.print(buffer);
			return wait(F("SEND OK"), REPLY_TIMEOUT);
		}
		return false;
	}

	void send_P(const char *str, byte link) {
		while (pgm_read_byte(str)) {
			String buffer = "";
			int n = 0;
			while (pgm_read_byte(str) && n < TX_BUF_SIZE) {
				buffer += (char)pgm_read_byte(str);
				n++;
				str++;
			}
			Serial.print(F("AT+CIPSEND="));
			Serial.println((String)link + "," + (String)n);
			if (wait(">", REPLY_TIMEOUT)) {
				Serial.print(buffer);
				wait(F("SEND OK"), REPLY_TIMEOUT);
			}
		}
	}
};