// 화살표함수

// let getTriangle = (base, height) => {
//     return base * height  / 2
// }
// console.log('삼각형의 면적:' + getTriangle(5, 2))

let getTriangle = (base, height) => base * height / 2  //명령 한줄이면 {}와 return 생략 가능

let getCircle = radius => radius * radius * Math.PI //인자 하나면 ()생략가능

console.log(`삼각형의 면적 ${getTriangle(5, 2)}`)
console.log(`원의 면적 ${getCircle(1)}`)