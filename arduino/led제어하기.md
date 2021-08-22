# led 제어하기 

- 하드웨어 장치

## 브레드 보드

- 납땜이 필요 없는 프로토타입용 보드
  - VCC(빨간색)
  - GND(검은색)
  - 부품 연결선

### 점퍼선

​	브레드 보드에 부품들을 서로 연결할 때 이용

### led 발광다이오드

​	전류가 흐르면서 빛을 발하는 반도체

​	다이오드: 전류를 한쪽 방향으로만 흐르게 함

​	과다 전류가 흐를 경우 파손, led 앞에 저항을 배치

### 저항

​	전기의 흐름을 제한

## led 연결방식

- 풀업 방식-> +가 위로

- 풀다운방식-> +가 아래로

  ~~~ c++
  const int pu_led_pin = 3;	//풀업 연결핀
  const int pd_led_pin = 4; // 풀다운 연결핀
  
  void setup() {
     pinMode(pu_led_pin, OUTPUT);
     pinMode(pd_led_pin, OUTPUT);
  }
  void loop() {
    digitalWrite(pd_led_pin, HIGH);
    digitalWrite(pu_led_pin, HIGH);
  // 풀업 LED 연결핀 출력 설정 // 풀다운 LED 연결핀 출력 설정
  // 풀다운 LED 연결핀 HIGH 출력 // 풀업 LED 연결핀 HIGH 출력
    // digitalWrite(pd_led_pin, LOW); // 풀다운 LED 연결핀 LOW 출력
    // digitalWrite(pu_led_pin, LOW);  // 풀업 LED 연결핀 LOW 출력
  ~~~

  

  ~~~ c++
  void loop()
  {
  // LED1만 ON
  digitalWrite(led1_pin, HIGH); // 3번 핀 HIGH 출력(on) digitalWrite(led2_pin, LOW); // 4번 핀 LOW 출력(off) digitalWrite(led3_pin, LOW); // 5번 핀 LOW 출력(off) digitalWrite(led4_pin, LOW); // 6번 핀 LOW 출력(off) delay(1000);
  }
  ~~~

  