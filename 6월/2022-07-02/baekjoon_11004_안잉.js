const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const [, k] = input[0].split(" ").map((v) => Number(v));
const [...A] = input[1].split(" ").map((v) => Number(v));

A.sort((a, b) => a - b);
console.log(A[k - 1]);
