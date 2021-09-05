# python-pycamera(2)

- 각종 설정
- 동영상촬영

## 텍스트 설정

- annotate_text: 표시할 문자열
- annotate_text_size: 텍스트 크기(6~160), 기본 32
- annotate_foregruond: 글자 색상
- annotate_background: 글자 배경색

~~~ python
#pycamera_basic_ex04.py
from picamera import PiCamera, Color
from time import sleep

camera = PiCamera()

camera.start_preview()
camera.annotate_text_size = 50
camera.annotate_background = Color('blue')
camera.annotate_foreground = Color('yellow')
camera.annotate_text = "Hello World"
sleep(5)
camera.capture('/home/pi/Desktop/text.jpg')
camera.stop(preview)
~~~

---

## 밝기 설정

- brightness: 0~100 지정, 기본값 50
- 대비설정
  - contrast: 0~100 지정
- 이미지효과(IMAGE_EFFECTS)
  - image_effect: 디폴트 none
    - none/negative/solarize/sketch/denoise/emboss/oilpaint/hatch/gpen/pastel/watercolor/film/blur/saturation(채도)/colorswap/washedout...

~~~ python
#pycamera_basic_ex05.py
from picamera import PiCamera
from time import sleep 

camera = PiCamera()

camera.start_preview()
for effect in camera.IMAGE_EFFECTS: #시퀀스객체
		camera.image_effect = effect  #default;none
		camera.annotate_text = "Effect: %s" % effect
    sleep(5)
camera.stop_preview()    
~~~

---

## 자동 화이트 밸런스(AWB_MODES)

- awb_mode 속성, default;auto
- WAB_MODES 값 목록(wab_modes변수에 리스트로 담겨있다)
  - off/auto/sunlight/cloudy/shade/tungsten/fluorescent/incandescent/flash/horizon

~~~ python
#pycamera_basic_ex06.py
from picamera import PiCamera
from time import sleep

camera = PiCamera()

camera.start_preview()
camera.awb_mode = 'sunlight'
sleep(5)
camera.capture('/home/pi/sunlight.jpg')
camera.stop_preview()
~~~

## 노출(EXPOSURE_MODES)

- exposure_mode 속성, default;auto

- EXPOSURE_MODES 값 목록

  - off/auto/night/nightpreview/backlight/spotlight/sports/snow/beach/verylong/

    fixedfps/antishake/fireworks

~~~ python
# pycamera_basic_ex07.py 노출
from picamera import PiCamera
from time import sleep

camera = PiCamera()

camera.start_preview()
camera.exposure_mode = 'beach'
sleep(5)
camera.capture('/home/pi/beach.jpg')
camera.stop_preview()

~~~

---

## 동영상 촬영

- start_recording(파일명): 동영상 촬영시작_ preview와 무관하게 시작됨
- stop_recording(): 동영상 저장

~~~ python
#pycamera_basic_ex08.py 비디오 녹화
import picamera
import time

with picamera.PiCamera() as camera:
		res = int(input('Resolution(1:320x240, 2:620x480, 3:1024x768)'))
		
		#선택한 값에 따라 해상도 설정
		if res == 3:
				camera.resolution = (1024, 768)
    elif res == 2:
    		camera.resolution = (620, 480)
    else:
    		camera.resolution = (320, 240)
    
    #파일명 입력
    filename = raw_input('File Name?')
    
    camera.framerate = 15  #초당 촬영가능한 frame
    #프리뷰 화면 표시
    camera.start_preview() #lcd연결하여 확인
    
    #촬영하고 파일 저장
    camera.start_recording(output = filename + '.h264')  #파일명.확장자
    
    #5초 대기
    camera.wait_recording(5)
    
    #촬영 종료 
    camera.stop_recording()
    
    #프리뷰 화면 종료
    camera.stop_preview()
~~~

