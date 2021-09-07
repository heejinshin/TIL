#include  <SimpleTimer.h>
#include <Led.h>

SimpleTimer timer;

Led led1(8);
Led led2(9);

void blink1(){
    led1.toggle();
}

void blink2(){
    led2.toggle();
}   

//callback 함수
void repeatMe(){
    Serial.print("Uptime (s):");
    Serial.println(millis()/1000);

}

void setup(){
    Serial.begin(9600);
    timer.setInterval(1000, blink1);
    timer.setInterval(500, blink2);
}

void loop(){
    timer.run();

}










//폴링 방식이기때문에 반드시 loop에서 run()호출.