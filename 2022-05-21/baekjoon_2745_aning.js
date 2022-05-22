const input = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ");
const num = input[0];
const baseB = parseInt(input[1]);
let answer = 0;

for (let i = 0; i < num.length; i++) {
  let currentNum = num.charCodeAt(i);
  if (currentNum >= 48 && currentNum <= 57) {
    answer += baseB ** (num.length - i - 1) * (currentNum - 48);
  } else if (currentNum >= 65 && currentNum <= 90) {
    answer += baseB ** (num.length - i - 1) * (currentNum - 55);
  }
}

console.log(answer);
