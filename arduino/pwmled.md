

## PWMLed

- **PWM**

  디지털 신호는 0과 1의 값만 가질수 있다. 이 디지털 신호의 0과 1의 비율을 조절하는 것이 PWM이다. 

  출처: https://dokkodai.tistory.com/188 [OSHW Alchemist]

- led 연결 가능한 핀: 9, 10, 11

  ~~~ 
  PWMLed red(9);
  PWMLed green(10);
  PWMLed blue(11);
  ~~~

- PWMLed.h

  ~~~ 
  #pragma once
  #include <Led.h>
  class PWMLed: public Led {
  protected:
      int value;
  public:
      PWMLed(int pin, int value=0);
      void setValue(int value);
  };
  ~~~

- 통신속도 맞추기

~~~ 
Serial.begin(speed);
~~~

speed: 통신속도, 초당 몇비트의 속도로 통신할 건지. 보통 9600비트로 많이 사용하고 baud rate라고도 한다. 시리얼 통신으로 연결된 두 장치는 같은 속도를 가져야 한다. (업로드했을때 포트 에러가 뜨던 이유), 양쪽의 속도가 안맞으면 데이터가 깨진다.