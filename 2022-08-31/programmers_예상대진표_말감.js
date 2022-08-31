function solution(n, a, b) {
  let answer = 0;
  while (a !== b) {
    a = parseInt((a + 1) / 2);
    b = parseInt((b + 1) / 2);
    answer += 1;
  }
  return answer;
}
