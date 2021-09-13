// 복수의 반환값을 개별 변수에 대입하기, js의 unpack기능
function getMaxMin(...nums){
    return [Math.max(...nums), Math.min(...nums)]  //인자를 나머지연산자로 안해주면 배열 통째로 인자 하나만 들어감
}

let result = getMaxMin(10, 35, -5, 78, 0)
console.log(result)

let[max, min] = getMaxMin(10, 35, -5, 78, 0)
//let[,min] = getMaxMin(10, 35, -5, 89, 0) //두번째 요소만 받음
console.log(max)
console.log(min)