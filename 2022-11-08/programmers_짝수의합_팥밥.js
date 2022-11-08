function solution(n) {
  let evenNumber = [];

  for (let i = 0; i <= n; i++) {
    if (i % 2 === 0) evenNumber.push(i);
  }
  return evenNumber.reduce((prev, cur) => prev + cur, 0);
}
