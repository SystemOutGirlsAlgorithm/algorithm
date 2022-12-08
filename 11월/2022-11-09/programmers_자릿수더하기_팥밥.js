function solution(n) {
  let numbers = n.toString().split("");

  return numbers.reduce((prev, cur) => +prev + +cur, 0);
}
