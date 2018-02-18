// il progetto RoboWiFi è stato pensato e realizzato a scopo didattico dal 
// prof. Fabrizio Tamigi. 
// Le successive modifiche, sempre a scopo didattico, dal prof Diomede Mazzone

#include "ESP8266.h"
#include "Webpage.h"

#define RLED 5
#define GLED 6
#define BLED 3
#define LED 13
#define ESP_EN 2

#define BOOT_DELAY 1000
#define WLAN_SSID "RoboWiFi"
#define IP_ADDRESS "192.168.1.1"
#define SERVER_PORT 80
#define BAUD_RATE 115200
#define BLINK_TIME 200

ESP8266 ap;

void setup() {
  pinMode(BLED + 1, INPUT);
  pinMode(GLED + 1, INPUT);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(ESP_EN, OUTPUT);
  digitalWrite(RLED, HIGH);
  digitalWrite(GLED, HIGH);
  digitalWrite(BLED, HIGH);
  digitalWrite(ESP_EN, LOW);

  boot_wait();
  digitalWrite(ESP_EN, HIGH);

	if (!ap.baud() || !ap.reset() || \
		!ap.init(F(WLAN_SSID), F(IP_ADDRESS), SERVER_PORT) || !ap.baud(BAUD_RATE))
		terminate();
}

void loop() {
	int link;
	String http_req = ap.receive(link);
	if (link != -1) {
		if (http_req.indexOf(F("GET / ")) != -1) {
			ap.send_P(link, webpage);
		}
		else {
      if (http_req.indexOf(F("POLAR /")) != -1) {
        int rho = http_req.substring(http_req.indexOf(F("POLAR /")) + 7).toInt();
        int phi = http_req.substring(http_req.indexOf(F("POLAR /")) + ((String)rho).length() + 8).toInt();
        analogWrite(GLED, 255 - rho*0.7*phi/255);
        analogWrite(BLED, 255 - rho*0.7*(360 - phi)/255);
        ap.send(link, "OK");
      }
		}
    ap.stop(link);
	}
}

void terminate() {
  while (true) {
    digitalWrite(LED, !digitalRead(LED));
    delay(BLINK_TIME);
  }
}

void boot_wait() {
  for (int n = 0; n < 4*BOOT_DELAY/BLINK_TIME; n++) {
    digitalWrite(LED, HIGH);
    delay(BLINK_TIME/4);
    digitalWrite(LED, LOW);
    delay(BLINK_TIME/4);
  }
}
