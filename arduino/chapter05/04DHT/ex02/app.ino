#include <MiniCom.h>
MiniCom com;
const int lm35_pin = A0; // LM35DZ 연결핀

void check(){
    int value = analogRead(lm35_pin);
    float ftp = (float)value/1024.0*5.0;
    ftp = ftp*100.0 + 0.5;
    com.print(1, "T:", ftp);
}

void setup(){
    com.init();
    com.setInterval(2000, check);
    com.print(0, "[[LM35]]");
    com.print(1, "Preparing LM35");
}

void loop() {
    com.run();
}