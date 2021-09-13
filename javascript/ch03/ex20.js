// 고차함수
// arrayWalk 기능을 갖는 forEach함수
function arrayWalk(data, f){
    for (var key in data) {
        f(data[key], key)
    }
}

function showElement(value, key){
    console.log(`${key}:${value}`)
}

function showElement2(value, key){
    console.log(`arr[${key}] = ${value}`)
}

// 인수의 개수를 따지지 않는 js의 특성 
function showElement3(value){
    console.log(value)
}

function showElement4(value, key, arr){
    console.log(`arr[${key}] = ${value}, [${arr}]`)
}

var ary = [1, 2, 4, 8, 16]
arrayWalk(ary, showElement)
arrayWalk(ary, showElement2)
arrayWalk(ary, showElement3)
arrayWalk(ary, showElement4)

ary.forEach(showElement)