function solution(my_string, num1, num2) {
  let myArr = [...my_string];
  let s1 = myArr[num1];
  let s2 = myArr[num2];

  myArr[num1] = s2;
  myArr[num2] = s1;

  return myArr.join("");
}
