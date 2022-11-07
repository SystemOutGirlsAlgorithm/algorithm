// 피보나치 응용 문제
// 피보나치랑 다른 점은 n=2면 2라는 점(피보나치는 n=2면 1)
function solution(n) {
  /*  시간 초과
      if(n === 1) return 1;
      if(n === 2) return 2;
  
      return (solution(n-1) + solution(n-2))%1234567;
  */
  let answer = 0;
  let f1 = 0,
    f2 = 1;

  // n+1을 하는 이유는 멀리뛰기 결과가 피보나치보다 n+1만큼 더한 값이기 때문
  for (let i = 2; i <= n + 1; i++) {
    answer = (f1 + f2) % 1234567;
    f1 = f2;
    f2 = answer;
  }
  return answer;
}
