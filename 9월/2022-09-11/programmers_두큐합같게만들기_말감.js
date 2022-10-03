const sum = (arr) => arr.reduce((a, b) => a + b, 0);

function solution(queue1, queue2) {
  let sum1 = sum(queue1),
    sum2 = sum(queue2);
  const target = (sum1 + sum2) / 2;
  const end = sum(queue1) * sum(queue2);
  let count = 0;
  let point1 = 0,
    point2 = queue1.length;
  const queue = [...queue1, ...queue2];
  while (target > count) {
    if (sum1 === target) return count;

    if (sum1 > target) {
      sum1 -= queue[point1++];
    } else {
      sum1 += queue[point2++];
    }
    count++;
  }
  return -1;
}
