//능동부저, 부저울리기 2초마다 9번핀 연결시.
const int buzzer_pin = 9;   //부저 연결핀

void setup()
{
    pinMode(buzzer_pin, OUTPUT);
}

void loop()
{
    digitalWrite(buzzer_pin, HIGH);
    delay(100);

    digitalWrite(buzzer_pin, LOW);
    delay(200);
}