const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const N = +Number(input[0]);

let nums = input[1].split(" ").map((items) => {
  return Number(items);
});
nums.sort(function (a, b) {
  return a - b;
});
console.log(`${nums[0]} ${nums[N - 1]}`);
