//splice->원본 변화, 출력값 확인하기
var data = ['A', 'B', 'C', 'D', 'E']
console.log(data.splice(3, 2, 'F', 'G'))  //삭제한 요소 반환
console.log(data)   //원본 변화된 것 출력
console.log('')
console.log(data.splice(3, 2))
console.log(data)
console.log('')
console.log(data.splice(1, 0, 'H'))
console.log(data)