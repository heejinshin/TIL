from time import sleep
from picamera import PiCamera

camera = PiCamera() 
camera.resolution = (1024, 768) 
camera.start_preview()

# Camera warm-up time
sleep(2)

camera.capture('foo.jpg', resize=(320, 240)) #캡처하는 순간에 사이즈 바꿈