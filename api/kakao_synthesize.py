#synthesize, 합성
#post방식전송(body data존재)
import requests
import io
from pydub import AudioSegment 
from pydub.playback import play
URL = "https://kakaoi-newtone-openapi.kakao.com/v1/synthesize" 
HEADERS = {
    "Content-Type" : "application/xml",
    "Authorization" : "KakaoAK 2f12d7f8f9ad3a8032284fecde4f44e1" }
DATA = """ 
<speak>
    그는 그렇게 말했습니다.
    <voice name="MAN_DIALOG_BRIGHT">잘 지냈어? 나도 잘 지냈어.</voice>
    <voice name="WOMAN_DIALOG_BRIGHT" speechStyle="SS_ALT_FAST_1">금요일이 좋아
    요.</voice>
</speak>
"""
res = requests.post(URL, headers=HEADERS, data = DATA.encode('utf-8'))
if res.status_code == 200: #에러코드 정상여부 확인
    sound = io.BytesIO(res.content)
    song = AudioSegment.from_mp3(sound)
    play(song)
else:
    print(res.status_code, res.text)  #에러확인


#음성 합성 결과를 파일로 저장하기
#with open("result.mp3", "wb") as f:
#   f.write(res.content)
#
#파일에서 재생하기
#song = AidioSegment.from_mp3("./result.mp3")

sound = io.BytesIO(res.content)
song = AudioSegment.from_mp3(sound)

play(song)

