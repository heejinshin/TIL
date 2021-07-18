# Iterable 자료형

- iterable 객체 - 반복 가능한 객체

- 대표적으로 iterable한 타입 - list, dict, set, str, bytes, tuple, range

  ~~~ python
  dict = {
      1 : 'a',
      2 : 'b',
      3 : 'c'
  }
  for i in dict:
      print(i) >>> 1 2 3
  ~~~

  시퀀스객체들을 for문으로 탐색이 가능한다. dictionary와 같은 경우 key값을 탐색한다. 그 순서는 일정하지 않을 수 있다. *순서무관 객체- 사전, 집합

- iterable객체를 만드는 iter()함수와 다음 출력요소를 꺼내주는 next()함수

  ~~~ python
  it = iter(dict)   #안해주고 next()반환할경우 오류 발생, TypeError: 'dict' object is not an iterator
  print(next(it))
  print(next(it))
  print(next(it))
  print(next(it))   #네번째에서 더이상 반복할게 없어 StopIteration예외가 발생하면 next()는 멈춘다.
  ~~~

  StopIteration예외가 발생하는것을 아래와 같이 예외처리 구문을 써볼 수 있다.

  ~~~ python
  it = iter(dict)   
  while True:
      try:
          print(next(it))
      except StopIteration:
          break     #예외 발생시 무한루프를 종료한다.
  ~~~

- iter()함수와 next()함수를 사용해서 for문을 사용하지 않고도 컬렉션 순회를 할 수 있다. 

  next()를 쓰려면 먼저 iter()를 사용해 iterable한 객체로 만들어줘야 한다.

