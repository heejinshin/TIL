# string객체와 c_str()

C언어에는 객체라는 개념이 없었다. 그래서 문자열을 표현할 때 char배열로 처리했는데 c++가 c언어를 완벽하게 호환성을 갖는다.

그렇다보니 예전에 사용한 char로 문자열을 표현하는 함수들이 존재한다. 주로 매개변수 타입이 char*..

c++에서는 문자열을 string객체로 처리한다. string객체는 문자열 데이터를 내부에 가지고 여러 메서드도 갖고있다. 그래서 string객체의 인스턴스의 시작주소와 실제 문자열 데이터의 시작 주소가 다르다. 따라서 char*에 string객체를 줄수가 없다. 

string의 c_str()메서드는 string 인스턴스의 내부 문자열 데이터의 시작 주소를 리턴해준다. 그래서 char*타입의 변수에 배정이 가능해진다. 

~~~ c++
string hello = "Hello";
char *pstr = hello.c_str();
~~~

c_str()은 입력처리에서 쓰지 않고, 출력 처리에서 쓰인다.

~~~ c++
print(1, str.c_str())
~~~

