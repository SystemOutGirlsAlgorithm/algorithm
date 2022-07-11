function solution(n) {
  let answer = 0;
  let arr = [];
  arr = String(n)
    .split("")
    .map((v) => Number(v));

  answer = arr.reduce((a, b) => a + b);
  return answer;
}
