const input = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ");
let decimal = parseInt(input);
let result = [];

if (decimal === 0) {
  result.push(0);
}

while (decimal !== 0) {
  if (decimal % 2 !== 0) {
    result.push(1);
    decimal = (decimal - 1) / -2;
  } else if (decimal === -1) {
    result.push(1);
    decimal = 1;
  } else if (decimal === 1) {
    result.push(1);
    decimal = 0;
  } else {
    result.push(0);
    decimal = decimal / -2;
  }
}

console.log(result.reverse().join("").trim());
