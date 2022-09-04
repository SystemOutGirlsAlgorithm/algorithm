const input = require("fs").readFileSync("/dev/stdin").toString();
const N = Number(input);
let star = "";
let result = "";

for (let i = 0; i < N; i++) {
  star += "*";
  result += star + "\n";
}

console.log(result);
