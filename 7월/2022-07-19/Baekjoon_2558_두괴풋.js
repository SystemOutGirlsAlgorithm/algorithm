const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const A = +input[0];
const B = +input[1];

function sum(num1, num2) {
  if (num1 < 0 || num2 > 10) {
    return;
  }

  return num1 + num2;
}

console.log(sum(A, B));
