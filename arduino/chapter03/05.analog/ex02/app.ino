//led에 pwm신호 출력하기
const int led_pin = 9;

void setup()
{
    pinMode(led_pin, OUTPUT);

}

void loop()
{
    int pwm_val;

    for(pwm_val = 0; pwm_val < 256; pwm_val += 5){
        analogWrite(led_pin, pwm_val);
        delay(100);
    }

    digitalWrite(led_pin, 0);
    delay(2000);
}

