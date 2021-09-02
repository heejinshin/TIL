#직선과 사각형의 교차점 리턴, clipLine()
import cv2
import numpy as np

#white 배경 색상
img = np.zeros(shape=(512, 512, 3), dtype=np.unit8) + 255  #white->255
#unit: unsigned integer

x1, x2 = 100, 400
y1, y2 = 100, 400
cv2.rectangle(img, (x1, y1), (x2, y2), (255, 0, 0), 2)
pt1 = 120, 50
pt2 = 300, 500
cv2.line(img, pt1, pt2, (255, 0, 0), 2)

imgRect = (x1, y1, x2-x1, y2-y1)  #width, height
retval, rpt1, rpt2 = cv2.clipLine(imgRect, pt1, pt2)

#교차점 원 그리기
if retval: 
    cv2.circle(img, rpt1, radius=5, color=(0, 255, 0), thickness=-1)
    #두께가 음수인경우 원의 내부 채움
    cv2.circle(img, rpt2, radius=5, color=(0, 255, 0), thickness=-1)

cv2.imshow('img', img)
cv2.waitKey()
cv2.destroyAllWindows()
