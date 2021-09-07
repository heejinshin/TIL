# 무한루프를 돌면서
# 사용자로부터 텍스트 입력을 받음(input 함수 사용)
# 입력받은 문자열을 음성 합성으로 재생하기

import requests
import io
from pydub import AudioSegment 
from pydub.playback import play

URL = "https://kakaoi-newtone-openapi.kakao.com/v1/synthesize" 
HEADERS = {
    "Content-Type" : "application/xml",
    "Authorization" : "KakaoAK 2f12d7f8f9ad3a8032284fecde4f44e1" }


# while True:
#     data = input("text를 입력하시오")
#     DATA = data
#     res = requests.post(URL, headers=HEADERS, 
#     data = DATA.encode('utf-8'))

#     if input:
#         sound = io.BytesIO(res.content) #디지털화
#         song = AudioSegment.from_mp3(sound)  #음성변환
#         play(song) #재생
#     else:
#         print(res.status_code, res.text)  

#강사님코드
def synthesize(text):
    DATA = f"<speak>{text}</speak>"
    res = requests.post(URL, headers = HEADERS, data = DATA.encode('utf-8'))
    if res.status_code == 200:
        return res.content
    else:
        print(res.status_code,res.text) #에러확인
def play_audio(audio):
    sound = io.BytesIO(audio)
    song = AudioSegment.from_mp3(sound)
    play(song)

while True:
    text = input('입력')
    audio = synthesize(text)
    if audio:
        play_audio(audio)


