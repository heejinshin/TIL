#ROI에 의한 블록 평균 영상
import cv2
import numpy as np

src = cv2.imread('./data/lena.jpg', cv2.IMREAD_GRAYSCALE)
dst = np.zeros(src.shape, dtype=src.dtype)

N = 4    #8, 32, 64 (512, 512)
height, width = src.shape   #영상크기얻는방법
#height, width, _ = src.shape   #컬러 영상

h = height // N   #int
w = width // N    #int

for i in range(N):
    for j in range(N):
        y = i * h
        x = j * w
        roi = src[y:y+h, x:x+w]
        dst[y:y+h, x:x+w] = cv2.mean(roi)[0]  #그레이스케일 영상, mean, 평균치, 1개
        #dst[y:y+h, x:x+w] = cv2.mean(roi)[0:3]  #컬러 영상이면 3차원배열이니까 슬라이싱
#GrayScale과 달리 img의 Channel이 3이므로 대입하는 값이 단일 값이 아닌 배열로서 3차원의 값을 대입하여야 한다
cv2.imshow('dst', dst )
cv2.waitKey()
cv2.destroyAllWindows()
