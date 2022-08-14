function solution(x, n) {
  const answer = new Array(n).fill(x).map((a, idx) => a + a * idx);
  return answer;
}
