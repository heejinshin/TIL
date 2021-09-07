#include <WifiMiniCom.h>
const char *ssid = "Campus7_Room4_2.4GHz"; const char *password = "12345678";
WifiMiniCom com;
void setup() {
    com.init(ssid, password);
}
void loop() {
    com.run();
}