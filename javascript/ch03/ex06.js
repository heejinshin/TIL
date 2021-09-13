// 스코프
scope = 'Global Variable'

function getValue(){
    scope = 'Local Variable'   //여기서 scope가 지역이 아니라 전역으로 동작한다, 선언시 지역으로 사용 가능
    test = 'abc'
    return scope
}

console.log(getValue())
console.log(scope)
console.log(test)