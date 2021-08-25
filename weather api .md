# OpenAPI

https://openweathermap.org/weathermap?basemap=map&cities=true&layer=temperature&lat=37.1965&lon=127.1163&zoom=5

~~~ 
http://api.openweathermap.org/data/2.5/weather?q={city}&APPID={API_KEY}& lang=kr
~~~

- 중괄호는 빼고 입력하여 url에 넣기 

- city부분에 알고싶은 도시의 이름을 api의 이름 그대로 넣는다. 

- Api_key에 가입 후 받은 key를 복사하여 넣는다. 

~~~ json
//결과 json(javascript object notation)
{
"coord": { "lon": 126.9778, "lat": 37.5683 }, 
  "weather": [	//날씨에 대한 요약 정보
{ "id": 800, "main": "Clear", "description": "맑음", "icon": "01d" } ],   
  "base": "stations",
  "main": {			//실제 값을 가짐
    "temp": 272.82,  //온도(켈빈온도값(절대온도)->섭씨로 환산 필요)
    "feels_like": 268.77, //체감온도
    "temp_min": 272.15,		//낮은오차범위
    "temp_max": 273.15,		//높은오차범위
    "pressure": 1028,		//기압
    "humidity": 34		//습도
		},
  "visibility": 10000,	//가시거리
  "wind": { "speed": 1.03, "deg": 120 },		//바람(풍속, 풍향)
  "clouds": { "all": 0 },	//구름
  "dt": 1612420804,
"sys": { //해가 뜨는시간, 지는시간, 타임존
"type": 1,
"id": 8105, "country": "KR", "sunrise": 1612391603, "sunset": 1612429114
  },
  "timezone": 32400,
  "id": 1835848,
  "name": "Seoul",
  "cod": 200
}
~~~

- 파이썬에서는 사전으로 처리, 사전의 모양을 취하는 문자열
- 정보가 구조화 되어있음
- 코드의 key부분은 위도와 경도값