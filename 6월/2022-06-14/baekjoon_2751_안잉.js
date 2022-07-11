const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((v) => Number(v));

const [testCase, ...num] = input;
const result = num.sort((a, b) => a - b);
console.log(result.join("\n"));
