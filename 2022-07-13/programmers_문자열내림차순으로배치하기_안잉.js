function solution(s) {
  var answer = "";
  s = s.split("").map((v) => v.charCodeAt(0));
  answer = s.sort((a, b) => b - a).map((v) => String.fromCharCode(v));
  return answer.join("");
}
