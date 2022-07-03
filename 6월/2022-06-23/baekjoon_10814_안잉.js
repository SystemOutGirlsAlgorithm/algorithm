const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const [, ...array] = input;

array.sort((a, b) => a.split(" ")[0] - b.split(" ")[0]);

console.log(array.join("\n"));
