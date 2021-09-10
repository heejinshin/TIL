//중첩된 객체 분해하기
let book = {
    title: 'Java 포켓 레퍼런스',
    publish: '기술평론사',
    price: 26800,
    other: {
        keywd: 'Java SE 8',
        logo: 'logo.jpgx'
    }
};

let {title, other, other: {keywd}} = book

console.log(title)
console.log(other)
console.log(keywd)