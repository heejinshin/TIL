# context manager

With ~ as ... 할때 __enter__()리턴

with코드 블럭을 벗어날때 __exit__() -> clean up작업

원하는 타이밍에 정확하게 리소스를 할당하고 제공하는 역할. 

## with문

가장 많이 사용되는 컨텍스트 매니저

코드블록 사이에서 한 쌍으로 함께 실행되어야 하는 연결된 수행코드가 두개가 있을 때 

~~~ python
with open('some_file', 'w')as opened_file:
	opened_file.write('Hola')
~~~

위 코드는 파일을 열어 어떤 데이터들을 쓰고 닫는 코드이다. 만약 데이터를 쓰는 동안 에러가 발생한다면, 파일을 닫으려고 시도할 것이다. 위 코드는 아래의 코드와 동일한 수행을 한다.

~~~ python
file = open('somefile', 'w')
try:
	file.write('Hola')
finally:
	file.close()
~~~

비교하면 간단히 with을 사용함으로써 많은 표준 코드들을 삭제했다. with문을 사용해서 가장 큰 장점은 감싸진 블록이 존재하든지 관심을 갖지 않아도 파일을 확실히 닫아준다는 것이다. 