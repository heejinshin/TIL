#동영상에서 얼굴 영역 추출
#추출기, 비디오 캡처 준비

import cv2
import numpy as np

face_classifier = cv2.CascadeClassifier('harrcascade_fullbody.xml')

cap = cv2.VideoCapture(0)   #pc에 웹캠이 하나 부착된 경우

#cap.get()

if cap.isOpened():     #format, 파이썬 문자열만드는 함수
    print('width: {}, height: {}'.format(cap.get(3), cap.get(4)))   #비디오 속성값 ID (0~18), 3과 4가 폭과 높이
else:
    print("No Camera")


#기본은 무한루프, esc눌렀을때 끝내는거
#캡처리드로 frame 얻어내고 나머진 똑같음, detect해주고 거기에 대해서 사각형 영역 해주는
while True:
    ret, frame =cap.read()
    if ret:
        gray = cv2.cvtColor(frame, cv2.COLOR_BG2GRAY)

        cropped_face = None
        #얼굴 검출
        bodies = classifier.detectMultiScale(gray, 1.3, 5)
        for (x, y, w, h) in faces:
            cropped_face = frame[y:y+h, x:x+w].copy()
            cropped_face = cv2.resize(cropped_face, dsize=(300, 300),
                                interpolation=cv2.INTER_AREA)

            cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 0, 255), 3)
    #에러발생가능, cropped_face가 notdefined: 최초 영상에서 얼굴이 검출이 안된 경우
        if cropped_face is not None:  #에러방지위함 코드, cropped_face가 리스트가 아니기때문에 (numpy배열) if cropped_face: 이렇게 검사 못하고 is not으로 none이 아니냐 검사를 해줘야한다. 
            cv2.imshow('face', cropped_face)   

        cv2.imshow('video', frame)  #video에  frame 보여주기

        if cv2.waitKey(1) == 27: break   #ESC 키  , 0이면 key입력이 있을때 까지 무한 대기 =
    else:
        print('error')