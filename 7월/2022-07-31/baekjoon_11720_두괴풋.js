const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
let nums = input[1].split("");
let result = 0;

for (let i = 0; i < input[0]; i++) {
  result += Number(nums[i]);
}

console.log(result);
