from io import BytesIO
from time import sleep
from picamera import PiCamera

#CREATE AN in-memory stream
my_stream = BytesIO()

camera = PiCamera
camera.start_preview()
#camera warm-up time
sleep(2)

camera.capture(my_stream, 'jpeg') #포맷지정필요

print(my_stream.tell()) #내부 file pointer(읽기/쓰기위치)확인

my_stream.seek(0) #파일포인터를 처음위치로 이동
with open('capture.jpg', 'wb')as f:
    f.write(my_stream.read())