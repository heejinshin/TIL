# 아두이노 serial

- switch 학습파트 

## serial.begin()

serial객체 : 보통 디버깅 용으로 쓴다. pc와 직렬통신(usb)을 담당한다.

​					디버깅 -> 변수값, 실행위치 등 확인 위함.

Arduino.h 파일에 정의

---

할일

- 속도설정(baurd rale, bps)
- arduino와 pc 클럭속도(통신속도)가 일정해야 데이터가 유지된다.  

~~~ c++
Serial.begin(115200);  		//속도 초기화
~~~

## serial.print()

- 아두이노에서 pc로 전송하는 기능
- 한 개의 데이터만 보낼 수 있다
- 들어가는 데이터 타입은 무관

## serial.println()

출력후에 줄 바꿈('\n')





