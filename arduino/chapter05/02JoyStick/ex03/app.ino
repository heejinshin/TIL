//조이스틱 상태 시리얼 모니터 출력하기
#include <MiniCom.h>
#include <Analog.h>
#include <Button.h>
#include <Servo.h>

MiniCom com;
Analog x(A1, 0, 180);
Button btn(A0);
Servo servo;

bool lock = false;
int lock_angle = 0;

void setup(){
    com.init();
    com.setInterval(100, check);
    com.print(0, "[[Joystick]]");
    btn.setCallback(onClick);
    servo.attach(7);
}

void loop(){
    btn.check();
    com.run();
}

void onclick(){
    lock = !lock;
    if(lock){       //lock이 걸린경우
        lock_angle = x.read();
        servo.write(lock_angle);
    }
}

void check(){
    int dx;

    dx=x.read();

    char buf[17];
    if(lock){
        sprintf(buf, "Lock %3d", lock_angle;)
    }else{
        servo.write(dx);
        sprintf(buf, "angle %3d", dx);
    }

    com.print(1, buf);
}