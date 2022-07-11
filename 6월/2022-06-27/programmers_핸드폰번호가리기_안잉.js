function solution(phone_number) {
  var answer = "";
  let array = phone_number.split("");

  for (let i = 0; i < array.length; i++) {
    if (array.length - i > 4) {
      answer += "*";
    } else {
      answer += array[i];
    }
  }

  return answer;
}
