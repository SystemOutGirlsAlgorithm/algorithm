function solution(my_string, n) {
  let myArr = [...my_string];
  let result = [];

  for (let i = 0; i < myArr.length; i++) {
    result.push(myArr[i].repeat(n));
  }
  return result.join("");
}
