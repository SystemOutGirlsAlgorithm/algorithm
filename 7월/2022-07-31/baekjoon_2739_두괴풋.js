const input = require("fs").readFileSync("/dev/stdin").toString().trim();
const N = input[0];
let result = "";

for (let i = 1; i <= 9; i++) {
  result += `${N} * ${i} = ${N * i}\n`;
}

console.log(result);
