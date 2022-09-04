function solution(s) {
  let answer = 0;
  for (let i = 0; i < s.length; i++) {
    if (answer >= 0 && s[i] === ")") return false;
    answer = s[i] === "(" ? answer - 1 : answer + 1;
  }
  return answer ? false : true;
}
