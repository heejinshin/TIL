# response 객체의 content 속성에 이미지 데이터 다운로드하여 저장
from threading import Thread
import requests
import time

def getHtml(url):
    resp = requests.get(url)
    with open('./image.png', 'wb') as f: #writebinary
        f.write(resp.content)

url = 'https://www.google.com/images/branding/googlelogo/2x/googlelogo_color_92x30dp.png'
t1 = Thread(target=getHtml, args=(url,))
t1.start()