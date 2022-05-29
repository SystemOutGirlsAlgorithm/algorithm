const input = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ");
const decimal = parseInt(input[0]);
const baseB = parseInt(input[1]);

let remainder = decimal;
let answer = [];

while (remainder / baseB !== 0) {
  let result = remainder % baseB;
  result >= 10 ? answer.push(String.fromCharCode(55 + result)) : answer.push(result);
  remainder = Math.floor(remainder / baseB);
}

answer = answer.reverse();

console.log(answer.join("").trim());
