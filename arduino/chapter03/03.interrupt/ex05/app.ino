#include <Led.h>
#include <Button.h>

Led leds[] = {
    Led(8), Led(9), Led(10), Led(11),
};

Button btn(2);

int out_no = -1;

void move_led(){
    out_no = (++out_no)%4;
    Serial.println(out_no);
    for(int n = 0; n < 4; n++){
        leds[n].setValue(n==out_no);
    }
}

void flash(void){
    if(!btn.debounce()) return;
    move_led();
}

void setup(){
    btn.attachInterrupt(flash); 
}

void loop(){    
}