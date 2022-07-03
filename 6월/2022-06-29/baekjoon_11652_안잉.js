const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((v) => BigInt(v));

const [, ...numbers] = input;
numbers.sort((a, b) => (a < b ? -1 : a > b ? 1 : 0));

let count = 1;
let maxValue = numbers[0];
let maxCount = 0;

numbers.forEach((v, i) => {
  next = numbers[i + 1];
  if (v === next) {
    count++;
  } else {
    count = 1;
  }

  if (count > maxCount) {
    maxCount = count;
    maxValue = v;
  }
});

console.log(String(maxValue));
