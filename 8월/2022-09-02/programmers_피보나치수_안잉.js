function solution(n) {
  let answer = 0;
  answer = fibonacci(n);
  return answer;
}

function fibonacci(n) {
  let F = new Array(n + 1).fill(0);
  F[1] = 1;
  for (let i = 2; i <= n; i++) {
    F[i] = (F[i - 1] + F[i - 2]) % 1234567;
  }
  return F[n];
}
