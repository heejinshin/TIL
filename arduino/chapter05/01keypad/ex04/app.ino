//타이머기능 추가한 버전

#include <MiniCom.h>
#include <Keypad.h>
#include "keymap.h"
#include <Led.h>

MiniCom com;
Led beep(13);


Keypad keypad(makeKeymap(keys),
                rowPins, colPins, ROWS, COLS);
String input="";
bool b_input = false; //키 입력 상태 변수, *누르면 true, #누르면 false
int timerId = -1;       //타임 아웃용 타이머 ID

void setup(){
    com.init();
    com.print(0, "[[Keypad Test]]");
}

void loop() {
    com.run();          //timer.run을 내부적으로 호출하고 있는것, 이거 없으면 타이머 동작 안함
    char key = keypad.getKey();   //이 동작 때매 동기적 기능 안쓰고 비동기 함수 쓰는것
    if(key){
        process(key);
    }
}

void process(char key){
    tick();
    SimpleTimer& timer = com.getTimer();
    if(key == '*' && b_input == false){
        input = "";  //초기화
        b_input = true;
        com.print(1, "start");
        timerId = timer.setTimeout(5000, reset);
    }else if(key =='#'){
        timer.deleteTimer(timerId);
        b_input = false;
        check();        //지금까지 모은 input 출력해주는 함수
    }else if(b_input){
        input += key;
        timer.restartTimer(timerId);
    }
    
}

void check(){
    com.print(1, input.c_str());
    delay(3000);
    com.print(1, "");   //3초 보여주고 out, but 입력기록은 남아있다
}


//led랑 수동부저 소리
void tick(){
    beep.on();
    delay(100);
    beep.off();
}

void reset(){
    com.print(1, "reset");
    input = "";
    b_input = false;
}