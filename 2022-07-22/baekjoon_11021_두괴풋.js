const input = require("fs").readFileSync("/dev/stdin").toString().split("\n");

for (let i = 1; i <= input[0]; i++) {
  let num = input[i].split(" ").map((item) => Number(item));
  console.log(`Case #${i}: ${num[0] + num[1]}`);
}
