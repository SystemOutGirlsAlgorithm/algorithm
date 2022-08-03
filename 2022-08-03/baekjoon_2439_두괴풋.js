const input = require("fs").readFileSync("/dev/stdin").toString();
const N = parseInt(input);
let star = "";
let result = "";

for (let i = 1; i <= N; i++) {
  let space = "";

  for (let j = i; j < N; j++) {
    space += " ";
  }

  star += "*";
  result += space + star + "\n";
}

console.log(result);
