#include "MiniCom.h"
#include "Keypad.h"
#include "keymap.h"
#include "Led.h"
#include <Servo.h>  




MiniCom com;                //13번 핀에 부저 연결해놨기 때문에 업로드 하면 소리부터 남
Led beep(13);           //한번 배정하면 다른번호로 못바꿈 but서버모터는 그때그때 쓸수도있고 안쓸수도 있기 때문에 attach로 제어가능, detach는 분리되서 제어 불가
Servo lock;                //attach 함수에서 번호 제어를 한다.(핀 연결)


Keypad keypad(makeKeymap(keys),
                rowPins, colPins, ROWS, COLS);
String input="";
String password = "486"; //도오락 비밀번호 
bool b_input = false; 
int timerId = -1;       //타임 아웃용 타이머 ID

void setup(){
    com.init();
    com.print(0, "[[Keypad Test]]");
    lock.attach(3);     //서버모터 신호선이 연결된 번호 , attach는 핀 연결로 위에 led beep(num)와 같은의미
    lock.write(0);
}

void loop() {
    com.run();          
    char key = keypad.getKey();   
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
        // com.print(1, "start");
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
    //비밀번호검사
    if(input == password){
        lock.write(90);
        delay(5000);
        lock.write(0);
    }else{ //틀렸을때
        for(int i=0; i <10; i++){
            tick();
            delay(100);
        }
    }
    // com.print(1, input.c_str());
    // delay(3000);
    // com.print(1, "");   //3초 보여주고 out, but 입력기록은 남아있다
}


//led랑 수동부저 소리
void tick(){
    beep.on();
    delay(100);
    beep.off();
}

void reset(){
    // com.print(1, "reset");
    input = "";
    b_input = false;
}


//마지막작업_디버깅용 코드 주석처리 