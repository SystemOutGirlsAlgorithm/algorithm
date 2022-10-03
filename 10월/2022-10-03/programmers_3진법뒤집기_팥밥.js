/*
주어진 자연수 n을 3진법 상에서 앞뒤로 뒤집은 후 그 값을 10진수로 return
*/

function solution(n) {
  return parseInt(n.toString(3).split("").reverse().join(""), 3);
}
