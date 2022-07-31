function solution(arr, divisor) {
  var answer = [];
  arr.map((v) => (v % divisor === 0 ? answer.push(v) : null));
  answer.sort((a, b) => a - b);
  if (answer.length === 0) answer.push(-1);
  return answer;
}
