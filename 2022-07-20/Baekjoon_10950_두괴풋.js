const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const T = +parseInt(input.shift());
let result = "";

for (let i = 0; i < T; i++) {
  let num = input[i].split(" ");
  result += +parseInt(num[0]) + +parseInt(num[1]) + "\n";
}

console.log(result);
