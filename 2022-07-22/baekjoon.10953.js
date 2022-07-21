const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

for (let i = 1; i <= input[0]; i++) {
  let num = input[i].split(",").map((item) => Number(item));
  console.log(num[0] + num[1]);
}
