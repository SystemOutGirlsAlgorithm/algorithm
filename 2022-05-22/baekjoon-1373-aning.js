const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("").reverse();
let answer = [];

for (let i = 0; i < input.length; i += 3) {
  const octal = input.slice(i, i + 3);
  let result = 0;
  for (let j = 0; j < octal.length; j++) {
    result += octal[j] * Math.pow(2, j);
  }
  answer.push(result);
}

console.log(answer.reverse().join(""));
