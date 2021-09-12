var data = []
data.push(1, 2, 3)   //stack운영하는것
console.log(data)
data.pop()
console.log(data)

var data = []
data.push(1, 2, 3)
console.log(data.shift()) //1
console.log(data) //2,3

data.unshift(1)  //push와 unshift는 리턴값이 없다
console.log(data)  