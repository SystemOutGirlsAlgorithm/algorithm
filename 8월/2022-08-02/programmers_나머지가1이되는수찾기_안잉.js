function solution(n) {
  for (i = 2; i < n; i++) {
    if (n % i === 1) {
      return i;
    }
  }
}
