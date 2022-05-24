const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("");
let answer = "";

input.forEach((str, i) => {
  const octal = parseInt(str, 8);
  let binary = octal.toString(2);
  while (i !== 0 && binary.length < 3) {
    binary = "0" + binary;
  }
  answer += binary;
});
console.log(answer);
