#include <ColorLed.h>

ColorLed leds(9, 10, 11);

void setup(){
    
}

void loop(){
    leds.random();
    delay(500);
}
