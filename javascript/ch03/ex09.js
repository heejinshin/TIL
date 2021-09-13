// call by reference는 원본 조작, 원시타입 데이터 외의 것을 전달할때
// call by reference에 해당됨

var value = [1, 2, 4, 8, 16]
function deleteElement(value){
    value.pop()
    return value
}

console.log(deleteElement(value))
console.log(value)