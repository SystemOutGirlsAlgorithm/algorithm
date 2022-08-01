const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const [[...n], [...m]] = [
  input[1]
    .split(" ")
    .map((v) => parseInt(v))
    .sort((a, b) => a - b),
  input[3].split(" ").map((v) => parseInt(v)),
];
let answer = [];

const bSerach = (arr, target) => {
  let minIndex = 0;
  let maxIndex = arr.length - 1;
  while (minIndex <= maxIndex) {
    let midIndex = Math.floor((minIndex + maxIndex) / 2);
    if (arr[midIndex] >= target) {
      maxIndex = midIndex - 1;
    } else {
      minIndex = midIndex + 1;
    }
  }
  return arr[minIndex];
};

for (let i = 0; i < m.length; i++) {
  bSerach(n, m[i]) === m[i] ? answer.push(1) : answer.push(0);
}

console.log(answer.join(" "));
