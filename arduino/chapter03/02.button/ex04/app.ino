//스위치 누를때 마다 4개의 led 순차 점멸(1개 led만 on)
#include <Led.h>

#define OFF 0
#define ON 1

const int sw_pin = 2;       //스위치 연결핀
Led leds[4] = {
    Led(8), Led(9), Led(10), Led(11)
};

int out_no = -1;        //출력 패턴 번호(0-3)

void setup(){
    Serial.begin(115200);
    pinMode(sw_pin, INPUT_PULLUP);  //Switch 연결핀 입력 설정
}

void loop(){
    check();
}

void check(){
    boolean o_sw, n_sw;

    o_sw = !digitalRead(sw_pin);
    delay(10);
    n_sw = !digitalRead(sw_pin);

    if(o_sw == OFF && n_sw == ON){
        onClick();
    }
}

void onClick(){
    out_no = (++out_no)%5;   //한바퀴돌면 5번째는 꺼진상태
    Serial.println(out_no);
    for(int n = 0; n < 4; n++){
        if(out_no == 4){
            leds[n].off();
        }else {
            leds[n].setValue(n==out_no);
        }
    }
}