#include "Led.h"   //현재 디렉토리에서 먼저 찾고, 없으면 라이브러리에서 찾음
//#include <Led.h>   //무조건 라이브러리에서 찾음

Led leds[4] = {Led(3), Led(4), Led(5), Led(6)};

int out_no = 0; //출력 값 출력 순서 번호(0-3)

void setup(){

}

void loop(){
    int n;

    for(n = 0; n < 4; n++){
        if(n==out_no){
            leds[n].on();
        }else{
            leds[n].off();
        }
        //leds[n].setValue(n==out_no);
    }
    out_no = (++out_no) % 4;
    delay(1000);
}