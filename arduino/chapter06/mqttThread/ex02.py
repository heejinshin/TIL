#get(url), 지정한 url을 요청해서 웹 서버로부터 받은 응담을 리턴
#response_text(웹서버가 리턴한 텍스트 저장)_content(웹서버가 리턴한 실제 데이터 저장)

from threading import Thread
import requests
import time

def getHtml(url):
    resp = requests.get(url)
    time.sleep(1)
    print(url, len(resp.text), resp.text) #한번 가공해서 불러온다, 읽을 수 있는형태
#text대신 content넣어서 비교해보기
t1 = Thread(target=getHtml, args=('https://naver.com',)) #url 읽는 작업 동기적으로 실행하도록 스레드 처리 
t1.start()

