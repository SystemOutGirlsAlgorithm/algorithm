function solution(d, budget) {
  let target = d.reduce((acc, cur) => (acc += cur));
  d.sort((a, b) => a - b);
  if (d[0] > budget) {
    return 0;
  }
  if (target <= budget) {
    return d.length;
  }
  for (let i = d.length - 1; i > 0; i--) {
    target = target - d[i];
    if (target <= budget) {
      return i;
    }
  }
}
