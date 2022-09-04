function solution(s) {
  var answer = "";
  s = s.split(" ");
  answer = `${Math.min(...s)} ${Math.max(...s)}`;
  return answer;
}
