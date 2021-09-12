var str1 = '뜰에 뜰에 뜰에는 닭이 있다.'

console.log(str1.indexOf('뜰'))
console.log(str1.lastIndexOf('뜰'))
console.log(str1.indexOf('뜰', 3))
console.log(str1.lastIndexOf('에', 5))  //'에'다음의 위치부터 왼쪽으로 가면서 찾음
console.log(str1.indexOf('가든'))
console.log(str1.startsWith('뜰'))
console.log(str1.endsWith('닭'))