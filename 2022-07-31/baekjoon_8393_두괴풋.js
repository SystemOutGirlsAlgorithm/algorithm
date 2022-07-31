const input = require("fs").readFileSync("/dev/stdin").toString().trim();
let result = 0;

for (let i = 1; i <= input; i++) {
  result += i;
}

console.log(result);
