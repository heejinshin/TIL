import numpy as np
import cv2

#모두 0으로 되어 있는 빈 canvas(검정색)
img = np.zeros((512, 512, 3), np.unit8) #튜플, 차원, 0으로 채우기, bgr(0, 0, 0)이면 검정색
#검정색 캔버스를 하나 만든것, 첫번째 좌표 pt1, 두번째 pt2(우측하단좌표)
cv2.line(img, (0, 0), (511, 511), (255, 0, 0), 5)

cv2.imshow('image', img)
cv2.waitKey(0)  #키 입력이 될때까지 무한 대기
cv2.destroyAllWindows()
