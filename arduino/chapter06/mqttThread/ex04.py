#Thread 상속 클래스 만들기
from threading import Thread
import threading

class WorkerThread(Thread):
    def __init__(self):
        super().__init__() 
        #속성 초기화 
    def run(self):
        #워커스레드 작업 정의
        pass
t = WorkerThread()
t.start()