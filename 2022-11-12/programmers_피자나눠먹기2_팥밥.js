function solution(n) {
  let result = 1;

  // 최소 공배수 구하고 그 값 나누기 6한 몫이 필요한 피자판수
  while (true) {
    if (result % n === 0 && result % 6 === 0) break;
    result++;
  }
  return result / 6;
}
