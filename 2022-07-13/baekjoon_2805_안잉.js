const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const [N, M] = input[0].split(" ").map((v) => Number(v));
const [...trees] = input[1].split(" ").map((v) => Number(v));

const bSerach = (arr, target) => {
  let min = 0;
  let max = Math.max(...arr);
  let answer = 0;

  while (min <= max) {
    let mid = Math.floor((min + max) / 2);
    let sum = 0;
    arr.map((v) => {
      if (v > mid) {
        sum += v - mid;
      }
    });

    if (sum >= target) {
      if (mid > answer) answer = mid;
      min = mid + 1;
    } else {
      max = mid - 1;
    }
  }
  return answer;
};

console.log(bSerach(trees, M));
