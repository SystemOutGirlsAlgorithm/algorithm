const input = require("fs").readFileSync("/dev/stdin").toString().trim();
const numInput = Number(input);
let result = "";

for (let i = numInput; i >= 1; i--) {
  result += i + "\n";
}

console.log(result);
