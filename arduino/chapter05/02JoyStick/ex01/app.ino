void loop(){
    int dx, dy;
    boolean sw;

    dx = analogRead(x_joystick);    //x축 방향 전압값(좌우)
    dy = analogRead(y_joystick);    //y축 방향 전압값(상하)
    sw = digitalRead(z_sw);     //z축 스위치 상태 읽기

    //x축 방향 조이스틱 전압값 출력
    Serial.print("X-axis=");
    Serial.println(dx);

    //y축 방향 조이스틱 전압값 출력
    Serial.print("Y-axis =");
    Serial.println(dy);

    //z축 스위치 삳ㅇ태 출력
    Serial.print("Z-switch=");
    if(sw == 0)Serial.println("0(ON)");
    else Serial.println("1(OFF)");

    delay(2000);
}