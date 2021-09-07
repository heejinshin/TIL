#include <SimpleTimer.h>

SimpleTimer timer;
int timerId;   //셋타임아웃 실행하면 리턴되는 아이디값, restart로 넘겨주려고

void reset(){
    Serial.print("reset---------");
}

void setup(){
    Serial.begin(115200);
    timerId = timer.setTimeout(2000, reset);

    delay(1000);
    timer.restartTimer(timerId);

}

void loop(){
    timer.run();
}