function solution(my_string) {
  let answer = "";
  let my_arr = [...my_string];

  for (let i = 0; i < my_arr.length; i++) {
    if (
      my_arr[i] == "a" ||
      my_arr[i] == "e" ||
      my_arr[i] == "i" ||
      my_arr[i] == "o" ||
      my_arr[i] == "u"
    )
      my_arr[i] = "";
  }

  answer = my_arr.join("");
  return answer;
  /* 다른 사람 풀이 replace 함수를 활용
  return my_string.replace(/[aeiou]/g, '');
  */
}
