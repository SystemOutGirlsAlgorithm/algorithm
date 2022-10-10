function solution(age) {
  // 미리 알파벳으로 이루어진 배열을 생성한 다음 age[i]의 값에 따른 알파벳을 answer에 추가
  var alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j"];
  var answer = "";
  age = age.toString();

  for (let i = 0; i < age.length; i++) {
    answer += alphabet[age[i]];
  }
  return answer;
}
