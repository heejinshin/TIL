# Array
---
python에 리스트가 있다면 js에는 Array가 있다. 
여러개의 데이터를 다룰때 쓴다. 
```var Hearo = ['아이언맨', '토르', '헐크']```
---
주요 멤버 
- length
- isArray(obj)
- toString()
- toLocalString()
- indexOf(elm[index]): 없으면 -1리턴
- lastIndexOf(elm[index])
- entries(): 모든 키, 값을 취득
- join(del): 배열 내 모든 요소를 구분자 del로 연결
- concat(ary): 지정 배열을 현재 배열에 연결
- splice: 다른것과 다르게 원본이 바뀐다, 인자로서 치환
---
추가/삭제
- pop() : 끝요소를 꺼내어 리턴 후 삭제
- push(data): 배열 끝에 요소를 추가
- shift(): 배열 앞에서 꺼내어 리턴 후 삭제
- unshifht(): 배열 앞에 요소 추가 
- push와 unshift는 반환값이 없다
---