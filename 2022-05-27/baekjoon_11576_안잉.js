const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.split(" ").map(Number));
const [baseA, baseB] = input[0];
const [testCase] = input[1];
const numbers = input[2].reverse();
let result = 0;
let answer = [];

for (let i = 0; i < testCase; i++) {
  result += numbers[i] * Math.pow(baseA, i);
}

while (result > 0) {
  answer.unshift(result % baseB);
  result = Math.floor(result / baseB);
}
console.log(answer.join(" "));
