function solution(n) {
  var answer = n;
  const nBinary = n
    .toString(2)
    .split("")
    .filter((v) => v === "1").length;
  let answerBinary = 0;
  while (answerBinary !== nBinary) {
    answer += 1;
    answerBinary = answer
      .toString(2)
      .split("")
      .filter((v) => v === "1").length;
  }
  return answer;
}
