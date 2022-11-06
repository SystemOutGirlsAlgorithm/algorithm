function solution(denum1, num1, denum2, num2) {
  // 분자
  let top = num1 * denum2 + num2 * denum1;
  // 분모
  let bottom = num1 * num2;
  let maximum = 1;

  // 약분
  for (let i = 1; i <= top; i++) {
    if (top % i === 0 && bottom % i === 0) maximum = i;
  }
  return [top / maximum, bottom / maximum];
}
