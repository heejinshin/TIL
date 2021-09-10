//분할대입
let book = {
    title: 'java포켓 레퍼런스',  //프로퍼티:객체리터럴(상수)
    publish: '기술평론사',
    price: 26800
}
let {price, title, memo='none'} = book

console.log(title)
console.log(price)
console.log(memo)

