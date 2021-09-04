import cv2
import sys

cascade_file = "harrcascade_frontalface_alt.xml"
cascade = cv2.CascadeClassifier(cascade_file)

image_file = "./data/face1.jpg"
output_file = "face1-mosaic.jpg" #모자이크한 파일 저장 이름

image = cv2.imread(image_file)
image_gs = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

cascade = cv2.CascadeClassifier(cascade_file)
face_list = cascade.detectMultiScale(image_gs, scaleFactor=1.1,
                    minNeighbors=1, minSize =(100, 100))

if len(face_list) == 0:
    print("no face")
    quit()

#확인한 부분에 모자이크 처리하기, 원본을 축소시켰다가 확대시키면 모자이크 처리 됨 
mosaic_rate = 30

print(face_list)
color = (0, 0, 255)

for(x,y, w, h) in face_list:
    face_img = image[y:y+h, x:x+w]  #얼굴 부분 자르기

    #자른 이미지를 지정한 배율로 축소하기
    face_img = cv2.resize(face_img, (w//mosaic_rate, h//mosaic_rate)) #1/30로 축소

    #축소한 그림을 원래 크기로 되돌리기
    face_img = cv2.resize(face_img, (w, h), interpolation=cv2.INTER_AREA) #inter_area: 한개의 점이 네개의 점으로 갈때 동일한 색으로 채우는것
    image[y:y+h, x:x+w] = face_img  #원래이미지 슬라이싱영역에 조작한 이미지를 대입


#랜더링 결과를 파일에 출력
cv2.imwrite(output_file, image)
