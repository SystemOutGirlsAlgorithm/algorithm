const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("").reverse();
let sum = "";
let result = [];

for (let i in input) {
  sum += input[i];
  result.push(sum.split("").reverse().join(""));
}

console.log(result.sort().join("\n").trim());
