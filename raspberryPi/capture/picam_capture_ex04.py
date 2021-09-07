from io import BytesIO
from time import sleep
from picamera import PiCamera 
from PIL import Image  #PIL(python image library)

# Create the in-memory stream 
stream = BytesIO()

camera = PiCamera()
print(camera.resolution)  #디폴트 해상도 확인
camera.rotation = 180  #180도 화면 회전

sleep(2)
camera.capture(stream, format='jpeg')

# 내용을 읽기위해 스트림을 되감기함(rewind) 
stream.seek(0) 
image = Image.open(stream)
image.show()