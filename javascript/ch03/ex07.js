var scope = 'Global Variable'
function getValue(){
    console.log(scope)  //아래 var로 선언한 scope를 hoistiong
    var scope = 'Local Variable'
    return scope
}
console.log(getValue())
console.log(scope)