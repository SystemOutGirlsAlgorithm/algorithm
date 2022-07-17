function solution(seoul) {
  let answer = "";
  answer += `김서방은 ${seoul.findIndex((v) => v === "Kim")}에 있다`;
  return answer;
}
