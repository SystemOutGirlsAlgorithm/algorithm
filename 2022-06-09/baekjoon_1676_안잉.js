const input = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ");
let num = Number(input[0]);
let answer = 0;

while (num >= 5) {
  answer += Math.floor(num / 5);
  num /= 5;
}

console.log(answer);
