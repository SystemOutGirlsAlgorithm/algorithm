function solution(s) {
  let answer = true;
  let sum = 0;
  s = s.split("");
  for (let i = 0; i < s.length; i++) {
    s[i] === "(" ? sum++ : sum--;
    if (sum < 0) {
      answer = false;
      return answer;
    }
  }
  answer = sum === 0 ? true : false;
  return answer;
}
