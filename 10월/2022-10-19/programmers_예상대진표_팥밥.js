// 다른 사람 풀이 참고
function solution(n, a, b) {
  const nextNum = (num) => Math.floor((num + 1) / 2);
  let round = 1;

  // a와 b의 값이 같아지면 반복문 종료
  while (a !== b) {
    if (nextNum(a) === nextNum(b)) break;
    a = nextNum(a);
    b = nextNum(b);
    round++;
  }
  return round;
}
