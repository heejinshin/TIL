#include <WifiMiniCom.h>
#include <PubSubClient.h>
#include <Led.h>

const char *ssid = "KT_GiGA_5G_Wave2_D4D7";
const char *password = "2hgaibc082";
const char *mqtt_server = "192.168.0.159";

WifiMiniCom com;

WiFiClient espClient;
PubSub

void wifi_connect() {
WiFi.begin(ssid, NULL); // 비밀번호가 없는 경우 NULL com.print(0, "try to connect");
Serial.println();
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print("."); }
com.print(0, "WiFi connected");
com.print(1, WiFi.localIP().toString().c_str()); Serial.println(); Serial.println(WiFi.localIP());
}

void setup() {
    com.init();
wifi_connect(); }


void loop() {
    com.run();
}