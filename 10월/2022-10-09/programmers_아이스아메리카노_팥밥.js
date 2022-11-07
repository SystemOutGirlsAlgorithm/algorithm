function solution(money) {
  // Math.floor를 안적어서 소수점까지 출력해서 오류 발생
  return [Math.floor(money / 5500), money % 5500];
}
