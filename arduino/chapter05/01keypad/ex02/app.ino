//키에 의미부여 , *과 #에 초기화, 출력기능넣기 

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

void setup(){
    com.init();
    com.print(0, "[[Keypad Test]]");
}

void loop() {
    char key = keypad.getKey();
    if(key){
        process(key);
    }
}

void process(char key){
    tick();
    if(key == '*' && b_input == false){
        input = "";  //초기화
        b_input = true;
        com.print(1, "start");
    }else if(key =='#'){
        b_input = false;
        check();        //지금까지 모은 input 출력해주는 함수
    }else if(b_input){
        input += key;
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