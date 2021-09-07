//스위치 눌려질때 마다 4개의 led순차 점멸, 1개의 led만 on
#include <Led.h>
#include <Button.h>     //현재 디렉토리 위치이기 때문에 ""사용

Button btn(2);
Led leds[4] = {
    Led(8), Led(9), Led(10), Led(11)
};

int out_no = -1;        //출력 패턴 번호(0-3)

void move_led(){
    out_no = (++out_no)%4;
    Serial.println(out_no);
    for(int n =0; n<4; n++){
        leds[n].setValue(n==out_no);
    }
}

void setup(){
    btn.setCallback(move_led);
}

void loop(){
    btn.check();
}