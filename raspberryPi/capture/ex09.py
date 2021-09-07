import numpy as np
import cv2

with PiCamera() as camera:
    camera.resolution = (620, 480)
    camera.framerate = 24

    image = np.empty(640*480*3,), dtype=np.unit8
    #image = image.reshape((480, 640, 3)) 3차원 OpenCV numpy 배열
    # print(image.shape)

    while True:
        camera.capture(image, 'bgr')
        cv2.imshow('frame', image)
        if cv2.waitKey(1) == 27: #esc키 입력시 종료
            break