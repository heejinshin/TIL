#include <MiniCom.h> 
#include <Button.h> 
#include <Melody.h> 
#include "pirates.h"

MiniCom com;
Button btn(2);
int length = sizeof(notes) / sizeof(int);
Melody melody(9, notes, durations, length);
void check() {
bool bplay = melody.toggle(true); //true, 일시정지시 이어서 재생하겠다
if(bplay) {
        com.print(0, "play");
    } else {
        com.print(0, "pause");
    }
}

void setup(){
    com.init();
    btn.setCallback(check);
    melody.play();   
    com.print(0, "play");   //위아래 두줄 없애면 처음부터 시작하지 않음
}
void loop(){
    com.run();
    melody.run();
    btn.check();
}