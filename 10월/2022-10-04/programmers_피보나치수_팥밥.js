function solution(n) {
  /* 이 코드는 시간 초과 뜸
  if(n === 0) return 0;
  if(n === 1) return 1;
  
  return (solution(n-1) + solution(n-2))%1234567;
  */

  let answer = 0;
  let f1 = 0,
    f2 = 1;

  for (let i = 2; i <= n; i++) {
    answer = (f1 + f2) % 1234567;
    f1 = f2;
    f2 = answer;
  }

  return answer;
}
