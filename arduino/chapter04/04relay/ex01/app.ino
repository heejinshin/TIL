#include <Button.h>

Button btn(2);

const int relay_pin = 12;   //com에 연결된 핀
boolean relay_out = LOW;

void check(){
    if(!btn.debounce()) return;

    relay_out = !relay_out;     // 릴레이 제어핀 출력값 반전
    digitalWrite(relay_pin, relay_out);     // 릴레이 제어핀 새 출력값 출력
}

void setup(){
    btn.attachInterrupt(check); //인터럽트방식으로 변경, FALLING 이 디폴트
    pinMode(relay_pin, OUTPUT);
}

void loop(){

}