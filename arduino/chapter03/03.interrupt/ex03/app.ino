#include <Led.h>

Led led(8);
boolean led_st = LOW;

const int sw_pin = 2;
int t1, t2;

void flash(void){
    //채터링 처리
    t2 = millis();
    if((t2-t1)<200) return;
    else t1 = t2;

    led_st = !led_st;
    led.setValue(led_st);
}

void setup(){
    pinMode(sw_pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(sw_pin), flash, FALLING);
    t1 = millis();
}

void loop(){}