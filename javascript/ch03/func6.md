### 스코프
- 전역 스코프: 함수 밖에서 선언한 변수
- 지역 스코프: 함수 안에서 선언한 변수

scope = 'Global Variable' //전역

#### use strict의 사용
- 변수를 선언하고 쓸 것을 약속
'use strict'

var scope = 'Global Variable'

function getValue(){
    var scope = 'local'
    var test = 'abc
    tet = 'abx  //test변수의 오타로 tet같은게 생기는 것 방지
    return scope
}