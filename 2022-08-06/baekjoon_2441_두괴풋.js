const input = require("fs").readFileSync("/dev/stdin").toString().trim();
const N = +Number(input);
let result = "";

for (let i = 0; i < N; i++) {
  let space = "";
  space += " ".repeat(i);

  for (let j = N - i; j > N - i - 1; j--) {
    let star = "";
    star += "*".repeat(j);
    result += space + star + "\n";
  }
}

console.log(result);
