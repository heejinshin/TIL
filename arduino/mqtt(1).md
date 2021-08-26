# MQTT(1)

- 하나의 통신규약, 메시지 전송시스템

- 서버의 역할을 하는 브로커와 클라이언트 역할을 하는 publisher(메시지를 전달하는 클라이언트), Subscriber(메시지를 수신하는 클라이언트)
- 서버의 역할인 브로커에 접속하여 Topic으로 메시지를 구분해가며 보내고 읽는다.
- PubSubClient 라이브러리 사용

## 주요 메서드

MqttCom 클래스 사용(WifiMiniCom 상속)

- MqttCom(const char *ssid, const char *password);

  \- 생성자

- void init(const char *ssid, const char *password, int no_lcd= false);

  \- 네트워크 초기화 및 lcd 사용 여부 지정

- void setServer(const char *server, const char *topic = NULL, MQTT_CALLBACK_SIGNATURE = NULL);

  \- Mqtt 관련 정보 설정

- void reconnect();

  \- 서버 재연결

- void run();

  \- 기본 운영 및 Mqtt 이벤트 처리

- void publish(const char *topic, const char *value);

  \- 지정한 토픽으로 메시지 publish

- randomSeed()

  \- 랜덤하게 클라이언트 배정

- client.connected()

  \- 클라이언트가 연결되었는지 여부

- status()

  \- 연결상태 반환