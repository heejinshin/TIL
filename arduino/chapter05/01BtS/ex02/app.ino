#include <BtMiniCom.h>

void receive_msg(String msg);

BtMiniCom com(13, 12, receive_msg);
int count = 0;

void receive_msg(String msg){
    char buf[17];
    sprintf(buf, "%d")%s", ++count, msg.c_str();
    com.print(1, buf);
    com.send("input value:"+msg);
}

void setup(){
    com.init();
    com.print(0, "[[Bluetooth]]");
}

void loop(){
    com.run();
}