function solution(my_string, letter) {
  // 내 풀이
  /*
  let stringArr = [...my_string];
  for (let i = 0; i < stringArr.length; i++) {
    if (stringArr[i] === letter) stringArr[i] = "";
  }
  return stringArr.join("");
  */
  // 다른사람 풀이
  const answer = my_string.split(letter).join("");
  return answer;
}
