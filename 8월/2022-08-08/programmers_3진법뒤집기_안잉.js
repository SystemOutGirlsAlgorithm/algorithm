function solution(n) {
  let answer = 0;
  let result = [];
  while (n > 2) {
    result.push(n % 3);
    n = Math.floor(n / 3);
  }
  result.push(n);
  result.reverse();
  for (let i = 0; i < result.length; i++) {
    answer += result[i] * 3 ** i;
  }
  return answer;
}
