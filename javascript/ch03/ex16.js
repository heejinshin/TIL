// ...를 이용한 배열의 전개(전개연산자 )
console.log(Math.max(15, -3, 78, 1))
console.log(Math.max([15, -3, 78, 1]))  // 인자로 배열 하나가 넘어옴->매개변수가 하나

data = [15, -3, 78, 1]
console.log(data)
console.log(...data)   // 배열의 요소를 펼쳐서 넘겨라-> 매개변수가 4개

console.log(Math.max(...data))

// 펼침연산자 활용
a = [1, 2, 3]
b = 4
c = [5, 6, 7]
console.log(...a, b, ...c)
d = [...a, b, ...c]
console.log(d)