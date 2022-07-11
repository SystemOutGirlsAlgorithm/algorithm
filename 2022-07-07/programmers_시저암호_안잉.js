function solution(s, n) {
  s = s.split("");
  let answer = "";
  s.forEach((v) => {
    if (v === " ") {
      answer += " ";
    } else {
      answer += String.fromCharCode(
        v.charCodeAt(0) > 90 ? ((v.charCodeAt(0) + n - 97) % 26) + 97 : ((v.charCodeAt(0) + n - 65) % 26) + 65
      );
    }
  });
  return answer;
}
