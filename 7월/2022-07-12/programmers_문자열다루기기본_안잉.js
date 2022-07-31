function solution(s) {
  var answer = true;
  s = s.split("");
  if (s.length === 4 || s.length === 6) {
    s.map((v) => {
      if (!Number.isInteger(Number(v))) answer = false;
    });
  } else {
    answer = false;
  }
  return answer;
}
