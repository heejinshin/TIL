#include <MiniCom.h>
#include <Led.h>

Led led(8);
MiniCom com;

void check(){
    int on = led.toggle();
    if(on){
        com.print(1, "led on");
    }else{
        com.print(1, "led off");
    }
}

void setup(){
    com.init();
    com.print(0, "[[MiniCom]]");
    com.setInterval(1000, check);
}

void loop(){
    com.run();
}