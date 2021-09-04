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

    def __enter__(self): #context manager
        return self
    
    def __exit__(self, type, value, trace_back): #self외 는 안씀
        if self.cap and self.cap.inOpened(): #장치가 있고, 장치가 열려있으면
            # print('video release-----') #확인용 print
            self.cap.release() #release
        cv2.destroyAllWindows()
        


#static메서드_인스턴스로 접근하지 않고 클래스로 접근하겠다는 뜻, Video.show()
    @staticmethod  #self쓰지x
    def show(image, exit_char=ord('q')): #ord()-> 문자의 아스키코드리턴
        cv2.imshow('frame', image)
        if cv2.waitKey(1) & 0xFF == exit_char: #종료하는 문자인가
            return False #종료선언
        return True #계속 진행
    
    @staticmethod
    def to_jpg(frame, quality=80):
        encode_param=[int(cv2.IMWRITE_JPEG_QUALITY), quality]
        is_seccess, jpg = cv2.imencode(".jpg", frame, encode_param)
        return jpg

if __name__ == '__main__':
    with Video(device=2) as video: #__enter__()호출
        for image in video:
            if not Video.show(image, 27): break
            #if not Video.show(image): break #q로 종료

    #with 블럭 벗어날 때 __exit__()호출
