function solution(s) {
  var answer = "";
  s = s.split(" ");
  answer = s.map((v) => v.charAt(0).toUpperCase() + v.substring(1).toLowerCase());
  return answer.join(" ");
}
