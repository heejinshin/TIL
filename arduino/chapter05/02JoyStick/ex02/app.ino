#include <MiniCom.h>
#include <Analog.h>
#include <Button.h>

MiniCom com;
Analog x(A1, 0, 180);
Analog y(A2, 0, 180);
Analog z(A0);

void check(){
    int dx, dy;
    boolean sw;

    dx = x.read();
    dy = y.read();
    sw = z.read();

    char buf[17];
    sprintf(buf, "%d, %d [%d]", dx, dy, sw);
    com.print(1, buf);
}

void setup(){
    com.init();
    com.setInterval(100, check);
    com.print(0, "[[Joystick]]");
}

void loop(){
    com.run();
}