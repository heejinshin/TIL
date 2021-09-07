//eeprom 쓰기위한 작업 추가 

#include <MiniCom.h>        
#include <Keypad.h>
#include "keymap.h"
#include <Led.h>
#include <Servo.h>
#include <storage.h>
#include <Button.h>


//eeprom을 활용한 비밀번호 관리
const int BASE_ADDRESS =100;    //비밀번호 저장주소
MiniCom com;                
Led beep(13);
Servo lock;
Button btn(2);          //비밀번호 설정 버튼


Keypad keypad(makeKeymap(keys),
                rowPins, colPins, ROWS, COLS);
String input="";
String inputStar="";       
String password ="";

bool b_input = false; 
int timerId = -1;      
bool bSetPassword = false; //패스워드 설정하는 상태인지 아닌지

void setup(){
    com.init();
    com.print(0, "[[Door Lock]");
    lock.attach(3);     
    lock.write(0);
    com.offLcd();  
    password = readRom(BASE_ADDRESS);  //eeprom에서 비밀번호 읽기!!, int값임 
    btn.setCallback(setPassword);
}

void setPassword(){
    bSetPassword = !bSetPassword;   //상태  반전
    if(bSetPassword){  //새 비밀번호 입력 시작
    input = "";
    inputStar = "";
    b_input = true;
    com.onLcd();
    }else{
        //새 비밀번호 입력 완료 
        password = input;
    }
}

void loop() {
    btn.check();
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


