#include <MiniCom.h>
#include <Analog.h>

MiniCom com;
Analog cds(A0, 0, 1023, 0, 100);
Led led(8);

void check(){
    int value = cds.read();
    led.setValue(value > 50);       //어두워지면 켜짐
    com.print(1, "illu:", value);
}

void setup(){
    com.init();
    com.setInterval(100, check);
    com.print(0, "[[CDS Test]]");
}

void loop(){
    com.run();
}