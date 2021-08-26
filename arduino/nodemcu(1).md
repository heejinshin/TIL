# NodeMCU(1)

- 오픈소스 사물인터넷 플랫폼
- 와이파이 기능이 구현된 개바보드
- ESPRESSIF사의 ESP8266-12 모듈을 사용

## 주요핀

- D3, D4, D8: 부팅모드 설정 
- D0: 슬립모드에서 벗어나기위함
- 사용에 제한이 없는핀: D1, D2, D5, D6, D7
- 내장 led: D4

## 개발환경 설정

- 파일 환경설정 

  - 추가적인 보드 매니저 URLs:

  ~~~ 
  http://arduino.esp8266.com/stable/package_esp8266com_index.json
  ~~~

- 툴> 보드매니저
  - ESP8266 검색 및 설치, 보드(2.7.4)
    -  NodeMCU 1.0 (ESP-12E Module) 선택

## 기본예제

- lcd 연결
  - VCC: VIN(5V)
  - GND: GND
  - SCL: D1
  - SDA: D2

~~~ c++
#include <와이파이헤더>
#include <미니컴헤더>

const char *ssid = "wifi명칭";
const char *password = "wifipwd";
MiniCom com;	//시리얼통신지원

void wifi_connect(){
	WIFI.begin(ssid, NULL);	//비밀번호가 없는경우 null값
	com.print(0, "try to connect");
	Serial.println();
	while(WIFI.status()!=WL_CONNECTED){
	delay(500);
	Serial.print(".");
	}
	com.print(0, "WIFI connected");
	com.print(1, WIFI.localIP().toString().c_str());
	Serial.println();
	Serial.println(WIFI.localIP());
}

void setup(){
	com.init();
	wifi.connect();
}

void loop(){
	com.run();
}
~~~

- Wifi.begin(ssid, pwd)

- Wifi.status()

- Wifi.localIP().toString().c_str(): ip주소를 string으로 변환하여 외부변수로 저장

-  minicom

  미니컴이란 콘솔 접속용으로 쓰이는 프로그램 중 하나로  보통 스위치는 화면 출력 단자가 없기 때문에 제어할 수 없는데, 이때 콘솔로 연결해서 미니컴을 이용해서 제어한다면, 출력 장치가 없는 장치도 제어할 수 있게 된다

