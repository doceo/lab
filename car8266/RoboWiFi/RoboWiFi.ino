//autore: prof. Fabrizio Tamigi


#include "ESP8266.h"
#include "Webpage2.h"

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define SPD_L 10
#define SPD_R 11

#define TRIG 6
#define ECHO 7

#define BOOT_DELAY 500
#define WLAN_SSID "RoboWiFi"
#define IP_ADDRESS "192.168.1.1"
#define SERVER_PORT 80
#define BAUD_RATE 1000000
#define MIN_DISTANCE 30
#define BLINK_TIME 150

ESP8266 ap;

String rho = "0", phi = "0";

void setup() {
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);

	digitalWrite(TRIG, LOW);

	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
	pinMode(SPD_L, OUTPUT);
	pinMode(SPD_R, OUTPUT);

	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
	analogWrite(SPD_L, 0);
	analogWrite(SPD_R, 0);

	delay(BOOT_DELAY);

	if (!ap.baud() || !ap.reset() || \
		!ap.init(F(WLAN_SSID), F(IP_ADDRESS), SERVER_PORT) || !ap.baud(BAUD_RATE))
		terminate();
}

void loop() {
	int link;
	String http_req = ap.receive(link);
	if (link != -1) {
		if (http_req.indexOf(F("GET")) != -1) {
			ap.send_P(webpage, link);
			ap.stop(link);
		}
		else {
			int polar_pos = http_req.indexOf(F("POLAR"));
			if (polar_pos != -1) {
				int sep_pos = http_req.indexOf(',', polar_pos + 7),
					end_pos = http_req.indexOf(' ', sep_pos + 1);
				rho = http_req.substring(polar_pos + 7, sep_pos);
				phi = http_req.substring(sep_pos + 1, end_pos);
			}
		}
	}
	motors(rho.toInt(), phi.toInt(), measure() > MIN_DISTANCE);
}

void motors(unsigned long rad, unsigned long ang, bool go) {
	unsigned long PWM_L = 0,
				  PWM_R = 0;

	bool fwd = false;
	if (ang >= 0 && ang <= 180)
		fwd = true;
	else
		ang = 360 - ang;

	if (go || !fwd) {
		if (ang >= 5 && ang <= 90) {
			PWM_L = (255 * rad) / 120;
			PWM_R = (255 * rad * ang) / (120 * 90);
		}
		else if (ang > 90 && ang <= 175) {
			PWM_L = (255 * rad * (180 - ang)) / (120 * 90);
			PWM_R = (255 * rad) / 120;
		}
	}

/*
	if (rad < 40);
		else if (ang >= 0 && ang <= 45) {
			PWM_L = 255;
			PWM_R = 128;
		}
		else if (ang > 45 && ang < 135) {
			PWM_L = 255;
			PWM_R = 255;
		}
		else if (ang >= 135 && ang <= 180) {
			PWM_L = 128;
			PWM_R = 255;
		}
*/

	analogWrite(SPD_L, PWM_L);
	analogWrite(SPD_R, PWM_R);
	digitalWrite(IN1, fwd);
	digitalWrite(IN2, !fwd);
	digitalWrite(IN3, fwd);
	digitalWrite(IN4, !fwd);
}

unsigned long measure() {
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG, LOW);
	
	return pulseIn(ECHO, HIGH) / 58;
}

void terminate() {
	pinMode(13, OUTPUT);
	while (true) {
		digitalWrite(13, !digitalRead(13));
		delay(BLINK_TIME);
	}
}
