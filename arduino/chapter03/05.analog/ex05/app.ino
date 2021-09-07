#include "Analog.h"
#include <PWMLed.h>

// Analog sensor(A0, 0, 1023, 255, 0);
Analog sensor(A0, 255, 0);     //h파일에 디폴트값이 없어야, 오버로드시 디폴트값을 주의할 것. 
PWMLed led(9);

void setup(){
}

void loop(){
    int pwm_val = sensor.read();
    led.setValue(pwm_val);
}