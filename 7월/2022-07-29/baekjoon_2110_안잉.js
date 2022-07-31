const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const [n, c] = input[0].split(" ").map((v) => Number(v));
input.shift();
const [...home] = input.sort((a, b) => a - b).map((v) => Number(v));

const bSerach = (arr, target) => {
  let start = 1;
  let end = arr[arr.length - 1] - arr[0];
  let mid = 0;

  while (start <= end) {
    mid = Math.floor((start + end) / 2);
    let value = arr[0];
    let count = 1;
    for (let i = 1; i < arr.length; i++) {
      if (arr[i] >= value + mid) {
        value = arr[i];
        count++;
      }
    }
    if (count >= target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return end;
};

console.log(bSerach(home, c));
