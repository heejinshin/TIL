# pithon-pycamera(1)

- 주요 프로퍼티
- 실습코드

## 주요 프로퍼티

| 프로퍼티            | 설명                                                         |
| ------------------- | ------------------------------------------------------------ |
| rotation            | 이미지를 회전시킴, 설정 가능한 값은 0, 90, 180, 270          |
| saturation          | 채도 -100~100 범위, 기본은 0                                 |
| sharpness           | 날카로운 정도. -100~100 범위. 기본은 0                       |
| Shutter_speed       | 셔터 스피드. ms단위. 기본은 0                                |
| vflip               | 카메라 출력을 수직 방향으로 반전시킴                         |
| Video_denoise       | 노이즈 제거 알고리즘 적용 여부. True로 적용. 기본은 True     |
| Video_stabilization | 손떨림 방지기능 .기본은 False                                |
| Zoom                | 줌 설정. (x, y, w, h)튜플로 부동소수형 0.0~1.0 범위로 지정. 기본은 (0.0,0.0, 1.0,1.0) |

- 미리보기 화면(preview화면 서비스를 잘 쓰진 않음)
  - start_preview(): 미리보기 화면을 생성
  - stop_preview(): 미리보기 화면을 닫음

~~~ python
#pycamera_basic_ex01.py 미리보기
from picamera import PiCamera
from time import sleep

camera = PiCamera()

#camera.rotation = 180  //180도 회전하기

camera.start_preview()
#camera.start_preview(alpha=200) //투명도설정(0~255)

sleep(10)
camera.stop_preview()  #미리보기 화면 정지
~~~

___

- 해상도 설정(resolution 프로퍼티)
  - resolution 속성에 해상도 설정값을 튜플로 지정
  - camera.resolution = (1024, 768).  #1024 x 768 해상도
  - 최대 해상도: 2592 x 1944 (이 경우 fps를 15이하로 설정 필요)
- 이미지 촬영하기(capture메소드 )
  - capture(파일명)	
    - 촬영한 이미지를 저장할 파일 경로를 매개변수로 지정

---

~~~ python
#picamera 라이브러리 임포트	
import picamera

#time 라이브러리 임포트
import time

#PiCamera 객체 인스턴스 생성
with picamera.PiCamera() as camera:
  
  #해상도를 선택하도록 함
  res = int(input('Resolution(1:320x240, 2:620x480, 3:1024x768)?'))
  
  #선택한 값에 따라 해상도 설정
  if res == 3:
    	camera.resolution = (1024, 768)
  elif res == 2:
    	camera.resolutuin = (640, 480)
  else:
    	camera.resolution = (320, 240)

  #파일명 입력받기_input
  filename = input('File Name?')
  
  #프리뷰 화면표시
  camera.start_preview()
  
  #1초 대기(time module)
  time.sleep(1)
  
  #프리뷰 종료
  camera.stop_preview()
  
  #촬영하고 저장
  camera.capture(filename + '.jpg')
~~~

---

~~~ python
#pycamera_basic_ex03.py 
#5초 간격으로 5장 사진 촬영하기_for문

camera.start_preview()

for i in range(5):
	  sleep(5)
    camera.capture(format('/home/pi/image{}.jpg', i))
    
camera.stop_preview() 
~~~

