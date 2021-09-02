#버튼을 누르면 녹화 시작
#버튼을 떼면 녹화 종료

from gpiozero import Button
from signal import pause
import cv2
from datetime import datetime

recorder = None         #VideoWriter 객체
recording_status = False       #녹화 중인지 여부에 대한 상태 변수

cap = cv2.VideoCapture(0)        #0번 카메라
frame_size = (int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)),
                int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)))
fourcc = cv2.VideoWriter_fourcc(*'XVID')                                

def start_record():
    global recorder, recording_status
    start = datetime.now()
    fname = start.strftime('./data/%Y%m%d_%H%M%S.mp4')
    recorder = cv2.VideoWriter(fname, fourcc, 20.0, frame_size)
    recording_status = True

def stop_record():
    global recorder, recording_status
    recording_status = False
    if recorder:
        recorder.release()
        recorder = None

button = Button(26)

button.when_pressed = start_record
button.when_released = stop_record

while True:
    retval, frame = cap.read()   #프레임 캡처
    if not retval: break

    if recording_status:   #if는 true일때 아래를 실행하니까 
        recorder.write(frame)  #녹화중일 경우에만 frame 쓰기 처리 

    cv2.imshow('frame', frame)

    key = cv2.waitKey(25)
    if key == 27: break   #esc누르면 종료됨

cap.release()

cv2.destroyAllWindows()  #열린 모든 창을 닫는다

