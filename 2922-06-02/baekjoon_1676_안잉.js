const input = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ");
const num = parseInt(input[0]);
let result = 1n;
let answer = 0;

for (let i = 1n; i <= num; i++) {
  result = result * i;
}

result = String(result).split("").reverse();

for (let i in result) {
  if (result[i] === "0") {
    answer++;
  } else {
    break;
  }
}

console.log(answer);
