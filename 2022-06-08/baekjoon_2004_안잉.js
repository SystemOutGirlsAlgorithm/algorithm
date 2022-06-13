const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map((v) => Number(v));
input.push(input[0] - input[1]);
let answer = [];

for (let i = 0; i < input.length; i++) {
  let num5 = input[i];
  let num2 = input[i];
  let divide5 = 0;
  let divide2 = 0;
  while (num5 >= 5) {
    divide5 += Math.floor(num5 / 5);
    num5 /= 5;
  }
  answer.push(divide5);
  while (num2 >= 2) {
    divide2 += Math.floor(num2 / 2);
    num2 /= 2;
  }
  answer.push(divide2);
}
const result5 = answer[0] - (answer[2] + answer[4]);
const result2 = answer[1] - (answer[3] + answer[5]);
console.log(Math.min(result5, result2));
