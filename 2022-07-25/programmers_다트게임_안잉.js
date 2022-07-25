function solution(dartResult) {
  let answer = [];
  let count = 0;
  let cal = 0;
  dartResult = dartResult.split("");

  for (let i = 0; i < dartResult.length; i++) {
    if (dartResult[i] === "S") {
      cal = cal ** 1;
    } else if (dartResult[i] === "D") {
      cal = cal ** 2;
    } else if (dartResult[i] === "T") {
      cal = cal ** 3;
    } else if (dartResult[i] === "*") {
      cal = cal * 2;
      if (count > 1) {
        answer[count - 2] = answer[count - 2] * 2;
      }
    } else if (dartResult[i] === "#") {
      cal = cal * -1;
    } else {
      if (dartResult[i] === "1" && dartResult[i + 1] === "0") {
        if (count >= 1) answer.push(cal);
        cal = 10;
        count++;
      } else if (dartResult[i - 1] === "1" && dartResult[i] === "0") {
        continue;
      } else {
        if (count >= 1) answer.push(cal);
        cal = Number(dartResult[i]);
        count++;
      }
    }
  }
  answer.push(cal);
  answer = answer.reduce((acc, cur) => acc + cur);
  return answer;
}
