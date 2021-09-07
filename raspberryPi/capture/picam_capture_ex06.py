#연속이미지캡처
from time import sleep 
from picamera import PiCamera

camera = PiCamera(resolution=(1080, 720), framerate=30)

camera.iso = 100
sleep(2)

camera.shutter_speed = camera.exposure_speed
camera.exposure_mode = 'off'
g = camera.awb_gains
camera.awb_mode = 'off'
camera.awb_gains = g

#고정된 설정으로 여러사진 찍기
camera.capture_sequence(['image{i:02d}.jpg' for i in range(10)])