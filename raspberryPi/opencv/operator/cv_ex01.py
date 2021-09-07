#영상 속성
import cv2
import numpy as np

img = cv2.imread('./data/lena.jpg') #imread(fileName, flag)
#fileName (str) – 이미지파일의 경로, # flag (int) – 이미지 파일을 읽을 때의 Option.
#img = cv2.imread('./data/lena.jpg', cv2.IMREAD_GRAYSCALE)

print('img.dmin=', img.ndim)   #차원의 개수 
print('img.shape=', img.shape)   # 각 차원의 요소 수 
print('img.dtype=', img.dtype)      #데이터타입

#np.bool, np.unit16, np.unit32, np.float32, np.float64, np.complex64
img = img.astype(np.int32)  #unit8
print('img.dtype=', img.dtype)

img = np.unit8(img)
print('img.dtype', img.dtype)