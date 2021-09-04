#detect image set
import cv2
from cv2.data import haarcascades  #xml이 있는(data)의 절대경로 저장해둠
from os import path
from video import Video

face_xml = path.join(haarcascades, 'haarcascade_frontalface_default.xml')
face_cascade = cv2.CascadeClassifier(face_xml)

FACE_WIDTH = 200
#좌측상단에 detect된 face부분의 크기를 정사각형 200/200으로 fix
