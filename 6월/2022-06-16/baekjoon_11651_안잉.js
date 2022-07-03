const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");

const [, ...nums] = input;
const arr = [];

const mergeSort = (arr) => {
  if (arr.length < 2) {
    return arr;
  }

  const mid = Math.floor(arr.length / 2);
  const left = arr.slice(0, mid);
  const right = arr.slice(mid);

  return merge(mergeSort(left), mergeSort(right));
};

const merge = (left, right) => {
  let leftIndex = 0;
  let rightIndex = 0;
  let result = [];

  while (leftIndex < left.length && rightIndex < right.length) {
    if (left[leftIndex][1] < right[rightIndex][1]) {
      result.push(left[leftIndex]);
      leftIndex++;
    } else if (left[leftIndex][1] === right[rightIndex][1]) {
      if (left[leftIndex][0] < right[rightIndex][0]) {
        result.push(left[leftIndex]);
        leftIndex++;
      } else {
        result.push(right[rightIndex]);
        rightIndex++;
      }
    } else {
      result.push(right[rightIndex]);
      rightIndex++;
    }
  }
  return result.concat(left.slice(leftIndex), right.slice(rightIndex));
};

for (let i in nums) {
  const [x, y] = nums[i].split(" ").map((v) => Number(v));
  arr.push([x, y]);
}

const answer = mergeSort(arr);
console.log(answer.join("\n").replace(/,/g, " "));
