# 반복문의 continue

파이썬 반복문에서 continue를 쓸때와 안쓸때의 차이는 코드의 핵심 부분이 너무 깊게 들여쓰기 되어 파묻히는걸 막아주는 장점이 있다. 

다음과 같이 비교해볼 수 있다

~~~ python
#continue를 쓰지 않았을 때 
for i in range(10):
  if i % 2 != 0:
    print(i)
#continue를 썼을 때
for i in range(10):
  if i % 2 == 0:
    continue
  print(i)  
~~~

continue를 썼을때가 print문의 들여쓰기 깊이가 더 얕아 보기 쉽게 작성할 수 있다. 

continue가 실행되면 그 즉시 다음줄 부터는 무시하고 반복1회를 종료한다. 그런 다음 반복문의 처음으로 돌아와서 다음 반복을 실행하는 것이다. 

