//문제
// 버튼을 한번 누른 경우 서보 모터 90도 회전
// 버튼을 한번 더 누르면 서보 모터 0도로 원복
#include <Analog.h>
#include <Servo.h>
#include <MiniCom.h>
#include <Button.h>

Button btn(2);

MiniCom com;
Analog a_value(A0, 0, 1023, 180, 0);
Servo myServo;
const int servo_pin = 5;

void check(){
    int angle = a_value.read();
    myServo.write(angle);
    com.print(1, "Angle:", angle);
}

void setup(){
    com.init();
    com.print(0, "Servo Test3");
    myServo.attach(servo_pin);
    com.setInterval(100, check);
}

void loop(){
    com.run();
}