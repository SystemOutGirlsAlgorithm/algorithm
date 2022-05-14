const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const testCase = parseInt(input[0]);
let answer = [];

const gcd = (a, b) => (a % b ? gcd(b, a % b) : b);

for (let i = 1; i <= testCase; i++) {
  const [, ...numbers] = input[i].split(" ").map(Number);
  let result = 0;
  for (let j = 0; j < numbers.length; j++) {
    for (let k = j + 1; k < numbers.length; k++) {
      const [num1, num2] = [Math.max(numbers[j], numbers[k]), Math.min(numbers[j], numbers[k])];
      result += gcd(num1, num2);
    }
  }
  answer.push(result);
}
console.log(answer.join("\n").trim());
