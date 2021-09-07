#include "storage.h"


void setup(){
    Serial.begin(115200);
    //공장에서 기본 도어락 비밀번호르 세팅하는 작업임

    writeRom(100, "486"); //기록되는 주소는 임의로 정하는것, 꼭 100으로 할필요 없음

    String password = readRom(100);
    Serial.println(password);    //read롬에서 pw읽어서 확인해보는 작업
}

void loop(){

}