const int var_pin = A0; //가변저항 연결핀
int analog_val;

void setup(){
    Serial.begin(115200);
}

void loop(){
    int digital_val;
    float ff;

    digital_val = analogRead(var_pin);
    ff = (float)digital_val / 1023. *5.0;

    Serial.print("Input Voltage(0~5V) =");
    Serial.println(ff);

    Serial.print("Digital Value(0~1023) =");
    Serial.println(digital_val);
    Serial.println("--------------------------------");

    delay(2000);
}
