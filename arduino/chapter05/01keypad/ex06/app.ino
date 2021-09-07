//5번폴더 마지막작업_디버깅용 코드 주석처리 
//키 입력 누를때 마다 lcd에 *가 출력
// 키입력 완료시 lcd지움

#include <MiniCom.h>        //lcd on, off기능 추가했음
#include <Keypad.h>
#include "keymap.h"
#include <Led.h>
#include <Servo.h>



MiniCom com;                
Led beep(13);
Servo lock;


Keypad keypad(makeKeymap(keys),
                rowPins, colPins, ROWS, COLS);
String input="";
String inputStar="";        //입력받을때 출력시킬 *문자열

String password = "486"; //도오락 비밀번호 
bool b_input = false; 
int timerId = -1;       //타임 아웃용 타이머 ID

void setup(){
    com.init();
    com.print(0, "[[Door Lock]");
    lock.attach(3);     //서버모터 신호선이 연결된 번호 , attach는 핀 연결로 위에 led beep(num)와 같은의미
    lock.write(0);
    com.offLcd();   //끈 상태로 시작하려고 
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
        inputStar = ""; //초기화, 전역변수기 때문에 누적된 값이 쌓이게 된다. *눌렀을때 초기화 시키게 하는 코드.!!
        b_input = true;
        com.onLcd(); //시작할때 lcdOn
        // com.print(1, "start");
        timerId = timer.setTimeout(5000, reset);
    }else if(key =='#'){
        timer.deleteTimer(timerId);
        b_input = false;
        check();        //지금까지 모은 input 출력해주는 함수
        com.offLcd(); //끝났을때 lcdOff
    }else if(b_input){
        input += key;
        inputStar += '*';
        com.print(1, inputStar.c_str());
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
    com.print(1, "");   //3초 보여주고 out, but 입력기록은 남아있다
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
    com.offLcd();
}


