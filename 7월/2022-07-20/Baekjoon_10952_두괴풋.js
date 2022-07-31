const input = require("fs").readFileSync("/dev/stdin").toString().split("\n");

for (let i = 0; i < input.length - 2; i++) {
  let num = input[i].split(" ").map((item) => Number(item));
  console.log(num[0] + num[1]);
}
