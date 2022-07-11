const input = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ");
const firstNum = parseInt(input[0] + input[1]);
const secondNum = parseInt(input[2] + input[3]);

console.log(firstNum + secondNum);
