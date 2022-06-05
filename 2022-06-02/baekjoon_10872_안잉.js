const input = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ");
const num = parseInt(input[0]);
let result = 1;

for (let i = 1; i <= num; i++) {
  result = result * i;
}

console.log(result);
