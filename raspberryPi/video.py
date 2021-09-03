import cv2

class Video:
    def __init__(self, **kargs):   #가변키워드인자
        device = kargs.get('device', -1)  #device라는 키워드가 없으면 -1로 초기화 하겠다
        file = kargs.get('file')  #file키워드가 없으면 none으로 초기화 하겠다
        #get()->키가 없을때 에러를 발생시키는 대신 none을 리턴, 사전에서 쓰는 메서드
        if device >= 0: #device 번호가 0보다 크면
            self.cap = cv2.VideoCapture(device)
        elif file:  #file이 지정됐을때
            self.cap = cv2.VideoCapture(file)    

    def __iter__(self):  #이터러블 객체 생성
        return self

    def __next__(self):  
        ret, image = self.cap.read() #카메라 읽기
        if ret: #성공하면
            return image #이미지 리턴
        else:
            raise StopIteration  #예외처리, for문 종료