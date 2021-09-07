#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
const char *ssid = "TECH2_2G";
const char *password = "tech21234!";
WiFiServer server(80);
LiquidCrystal_I2C lcd(0x3F, 16, 2);
void wifi_connect() {
  ...
}
void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  wifi_connect();
  server.begin();
}
void loop() {
  WiFiClient client = server.available();
if (!client) { return;
}
  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available()) {
delay(1); }
// Read the first line of the request
String request = client.readStringUntil('\r'); Serial.println(request);
client.flush();
// Return the response client.println("HTTP/1.1 200 OK"); client.println("Content-Type: text/html"); client.println(""); // do not forget this one client.println("<!DOCTYPE HTML>"); client.println("<html>"); client.print("HELLO WORLD!"); client.println("</html>");
delay(1);
Serial.println("Client disonnected"); Serial.println("");
}