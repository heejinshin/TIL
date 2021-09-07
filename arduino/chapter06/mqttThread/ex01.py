# 스레딩 모듈의 Thread()를 호출하여 Thread 객체 생성
# 생성자에 실행 함수와 인자를 전달
# 스레드 객체의 start()메서드 호출
import threading

def sum(low, high):
    total = 0
    for i in range(low, high):
        total += i
    print('Subthread', total)

t = threading.Thread(target=sum, args=(1, 1000))  #sum함수에 인자전달
t.start()

print("Main Thread")
# main함수가 끝나도 작업스레드는 아직 실행중, 따라서 먼저 결과호출 