#스레드 클래스 상속 방법, run메서드 구현
import threading, requests, time

class HtmlGetter(threading.Thread):
    def __init__(self, url):
        super().__init__()
        self.url = url
    
    def run(self):
        resp = requests.get(self.url) 
        time.sleep(1)
        print(self.url, len(resp.text), resp.text)  
        #결과가 content형식처럼 뜬다..! 여쭤보기__  


t = HtmlGetter('https://google.com') 
t.start()

print("### End ###")