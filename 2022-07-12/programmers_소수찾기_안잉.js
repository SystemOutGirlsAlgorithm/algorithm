function solution(n) {
  let answer = 0;
  let isPrime = new Array(1 + n).fill(true);
  isPrime[0] = false;
  isPrime[1] = false;

  for (let i = 2; i <= Math.ceil(Math.sqrt(n)); i++) {
    if (isPrime[i]) {
      for (let j = 2; j <= n / i; j++) {
        isPrime[j * i] = false;
      }
    }
  }

  isPrime.map((v) => (v ? answer++ : null));
  return answer;
}
