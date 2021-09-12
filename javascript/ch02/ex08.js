//number객체 // 전부 문자열 리턴
var num1 = 255; console.log(num1.toString(16)); 
console.log(num1.toString(8));

var num2 = 123.45678; 
console.log(num2.toExponential(2)); 
console.log(num2.toFixed(3)); 
console.log(num2.toFixed(7)); 
console.log(num2.toPrecision(10)); 
console.log(num2.toPrecision(6));

//아래 둘은 메서드가 아니라 함수임
let n = parseInt('123') //문자열을 정수로 변환
console.log(n, typeof n)

let f = parseFloat('23.567')        //문자열을 실수로 변환
console.log(f, typeof f)

//자주쓰는것 toFixed(), parseInt(), parseFloat() 세가지 기억하기

