#include <MqttCom.h>
#include <Led.h>
const char *ssid = "Campus7_Room4_2.4GHz";
const char *password = NULL;
const char *mqtt_server = "192.168.0.159"; // mqtt broker ip address

MqttCom com;
Led led(BUILTIN_LED);
int value = 0;

void callback(char *topic, byte *payload, unsigned int length) { char buf[128];
memcpy(buf, payload, length); buf[length] = '\0';
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    Serial.println(buf);
    if (buf[0] == '1') {
        led.setValue(LOW);
} else { led.setValue(HIGH);
} }

void publish() {
    char msg[50];
++value;
snprintf(msg, 75, "hello world #%ld", value); Serial.print("Publish message: "); Serial.println(msg);
com.publish("outTopic", msg);
}
void setup() {
    com.init(ssid, password);
    com.setServer(mqtt_server, "inTopic", callback);
    com.setInterval(2000, publish);
}
void loop() {
com.run();
}