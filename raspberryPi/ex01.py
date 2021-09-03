import cv2
#xml파일 필요
#xml파일이란 태그 변수명을 사용자 지정하여 쓸 수 있는 파일
cascade_file = "haarcascade_frontalface_alt.xml"
#상대경로임, 현재파일과 같은 경로에 있어야함
cascade = cv2.CascadeClassifier(cascade_file)

image_file = "./data/face1.jpg"   #./data/face2.jpg
image = cv2.imread(image_file)
image_gs = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY) #검출 속도 높이기 위함, 흑백이미지 사용

face_list = cascade.detectMultiScale(image_gs, scaleFactor = 1.1,
                minNeighbors=1, minSize=(150, 150))

if len(face_list) > 0: #검출한게 있으면
    print(face_list)  #형태한번 찍어보고
    color = (0, 0, 255)
    for face in face_list:
        x, y, w, h = face
        cv2.rectangle(image, (x, y), (x+w, y+h), color, thickness=8)                
            #컬러 원본이미지를 사각형 표현
    cv2.imwrite("facedetect-output.PNG", image)  #png 파일 저장
else:
    print("no face")