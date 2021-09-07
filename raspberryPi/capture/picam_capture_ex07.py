from time import sleep
from picamera import PiCamera

camera = PiCamera() 
camera.start_preview() 
sleep(2)

#끝나는지점 생성x, 무한루프
for filename in camera.capture_continuous('img{counter:03d}.jpg'): 
    print('Captured %s' % filename)
    sleep(10) # wait 10 seconds