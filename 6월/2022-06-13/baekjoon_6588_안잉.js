const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((v) => Number(v));
input.pop();

const maxNum = Math.max(...input);
let isPrime = new Array(maxNum + 1).fill(true);
isPrime[0] = false;
isPrime[1] = false;
let arr = [];
let answer = "";

for (let i = 2; i <= Math.ceil(Math.sqrt(maxNum)); i++) {
  if (isPrime[i]) {
    for (let j = 2; j <= maxNum / i; j++) {
      isPrime[i * j] = false;
    }
  }
}

isPrime.forEach((v, i) => {
  if (v) {
    arr.push(i);
  }
});

input.forEach((v) => {
  for (let i = 0; i < arr.length; i++) {
    let possible = false;
    for (let j = 0; j < arr.length; j++) {
      let sum = arr[i] + arr[j];
      if (sum > v) {
        break;
      }
      if (sum === v) {
        answer += `${v} = ${arr[i]} + ${arr[j]}\n`;
        possible = true;
      }
    }
    if (possible) {
      break;
    }
  }
});

console.log(answer.trim());
