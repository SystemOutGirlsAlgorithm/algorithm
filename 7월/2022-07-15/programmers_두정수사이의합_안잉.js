function solution(a, b) {
  a > b ? ([a, b] = [b, a]) : null;
  var answer = 0;
  for (let i = a; i <= b; i++) {
    answer += i;
  }
  return answer;
}
