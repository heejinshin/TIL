# 기본자료형 객체
--- 
* py와 비교하여 정리
--- 
Number: 정수 실수
Boolean: true/false
String: 문자열
Object: 일반객체
Array: 배열
Math: 수학 연산
Date: 날짜
RegExp: 정규표현식
length: 문자열의 길이 ; 파이썬 len(s)
파이썬 리스트처럼 js 배열에도 length가 있다. 요소의 개수 또는 글자의 개수를 알 수 있다.
기본 데이터형에서는 new를 사용하지 않고 형 변환이 가능하다
## string 객체
--- 
py와 마찬가지로 불변객체이다,원본이 아니고 조작된 새로운 문자열이 반환됨
--- 
- indexOf: 서브 문자열을 찾는다.[]의 인덱스 부터 찾도록(find)
- lastIndexOf(): 오른쪽 부터 찾는다 찾기 시작할 문자를 두번째 인자로 지정(rfind)
- startWith()
- endsWith()
- includes()
--- 
* 부분 문자열
- charAt(n): n+1번째의 문자를 추출
- slice(start[.end]) : 문자열부터 start + 1~end 번째 문자를 추출
- substring(start, [.end]) : 뽑는 끝나는 위치 지정하여 뽑기
- substr(start[,cnt]): cnt개수만큼 뽑아달라
- split(str[,limit])
---
- 정규표현
- 대문자<->소문자
- 코드변환
- 그외 문자열변환