#include <MiniCom.h>
#include <Keypad.h>
#include "keymap.h"
MiniCom com;


Keypad keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String input="";

void setup(){
    com.init();
    com.print(0, "[[Keypad Test]]");
}

void loop(){
    char key = keypad.getKey();

    if(key){
        // String str(key); //글자하나추가
    
        input += key; //키 입력 누적되게
        com.print(1, input.c_str());
    }
}