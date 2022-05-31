const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.split(" ").map(Number));
const [start, finish] = input[0];

const isPrime = new Array(finish).fill(true);
isPrime[0] = false;
isPrime[1] = false;

let result = [];

for (let i = 2; i <= Math.ceil(Math.sqrt(finish)); i++) {
  if (isPrime[i]) {
    for (let j = 2; j <= finish / i; j++) {
      isPrime[j * i] = false;
    }
  }
}

for (let m = start; m <= finish; m++) {
  if (isPrime[m]) {
    result.push(m);
  }
}

console.log(result.join("\n").trim());
