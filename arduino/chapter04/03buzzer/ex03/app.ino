#include <Melody.h>
#include "mario.h"

//length는 배열의 길이가 된다
int length = sizeof(notes)/sizeof(int);   //notes의 크기 리턴(byte),요소의크기가 프로그램별로 배열 요소개수 센다
Melody melody(9, notes, durations, length);

void setup(){
    melody.play();
}

void loop(){
    melody.run();
}