//4개의 순차점멸(led풀업 연결) 배열이용
const int led_pin[4] = {3, 4, 5, 6}; //led 연결 핀 번호

//led 연결핀에 차례로 출력할 값
const int led_out[4][4] = {
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
};

int out_no = 0;     //출력 값 출력 순서 번호(0-3), 초기화 0

void setup(){
    int n;      //타입선언

    for(n=0; n <4; n++){            //초기화, 조건, 증감문 존재
        pinMode(led_pin[n], OUTPUT);  //핀모드설정(핀, 출력모드)
        digitalWrite(led_pin[n], LOW);      //쓰기값(핀번호, 전압설정, low는 0)
    }
};

void loop(){
    int n;
                    //n을 굳이 왜 설정하는거지, 반복문 0~3까지 돌려주려고
    for(n = 0; n < 4; n++){   //led 4개(0~3)
        //led_pin[n]번핀에 out_no 패턴 출력, 출력값 0~3
        digitalWrite(led_pin[n], n == out_no);
    }

    // out_no++;       //다음 출력 패턴 번호 설정
    // if(out_no == 4)out_no =0;       //마지막 다음은 처음 패턴으로 
    out_no = (out_no+1)%4;
    
    delay(1000);   //동작확인목적
}