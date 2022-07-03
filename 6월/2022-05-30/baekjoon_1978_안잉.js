const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.split(" ").map(Number));
const [testCase] = input[0];
const numbers = input[1];
let result = [];

for (let i = 0; i < testCase; i++) {
  if (numbers[i] !== 1 && numbers[i] !== 0) {
    let count = 0;
    for (let j = 2; j < numbers[i]; j++) {
      if (numbers[i] % j === 0) {
        count++;
      }
    }
    if (count === 0) {
      result.push(numbers[i]);
    }
  }
}

console.log(result.length);
