#include <Led.h>
#include <Button.h>

Led led(8);
Button btn(2);

boolean led_st = LOW;

void flash(void){
    if(!btn.debounce()) return;

    //led_st = !led_st; //led상태반전
    //led.setValue(led_st);
    led.toggle();
}
void setup(){
    btn.attachInterrupt(flash);
}

void loop(){}