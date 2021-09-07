# client가 음성 전송하면 kakao가 인식결과를(text)
# text로 리턴해주고
# 우리는 그걸 json화 시키는 코드를 짜볼것
import requests
import json

kakao_speech_url = "https://kakaoi-newtone-openapi.kakao.com/v1/recognize"

rest_api_key = '<2f12d7f8f9ad3a8032284fecde4f44e1>'

headers = {
    "Content-Type": "application/octet-stream",
    "X-DSS-Service": "DICTATION",
    "Authorization": "KakaoAK" + rest_api_key,
}

with open('heykakao.wav', 'rb') as fp:
    audio = fp.read()

res = requests.post(kakao_speech_url, headers = headers, data = audio)

print(res.text)

try:
    result_json_string = res.text[
        res.text.index('{"type":"finalResult"'):res.text.rindex('}')+1
    ]
    result = json.loads(result_json_string)
    value = result['value']
except: #인식실패
    value = None

print('[인식결과]', value)

#사전
result = json.loads(result_json_string) #문자열->사전
print(result)
print(result['value'])


#find->없으면 -1 리턴
#index->없으면 예외발생
