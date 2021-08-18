# 아두이노



button.cpp 기본골격, 헤더파일 부분 가져와서 수정

~~~ 
#include "Button.h"

Button::Button(int pin){

}
void Button::setCallback(button_callback_t callback){

}
int Button::read(){

}
void Button::check(){

}
~~~



## 변수 차이점

위치의 차이도 있지만 언제 메모리에 생겨서 언제 사라지나 하는 lifetime의 차이도 있다 

- 지역변수: 블럭 내에(함수내에) 선언되어있으면, 함수 호출시점에서만 쓸수있다. 

- 멤버변수: 인스턴스의 생명주기와 같다. 인스턴스가 생겼을때 생겼다가 인스턴스(btn)가 사라질때 멤버변수도 같이 사라진다.

  ~~~ 
  Button btn(2);
  만들면 pin이라는 멤버변수 생긴다. 2를 pin에 집어넣는것
  ~~~

  인스턴스가 하나 생긴다는거는 변수선언시 메모리에 인스턴스가 하나 만들어지고 pin이라는 변수와 callback이라는 변수의 공간이 할당된다. 

  생성자의 값에 의해 callback변수는 null로 pin은 2로 설정된것. 

  check라는 함수를 호출해야만 생기는 것이기 때문에 (btn.check()) , 스택에. 

  pin에 데이터값은 갖고있지는 않는다. 

- 전역변수: 선언된 시점 ~ 프로그램이 끝날때 까지

## 함수

함수명은 해당 함수에 대한 참조다. 모든 함수명은 함수의 주소값을 가지고 있다.