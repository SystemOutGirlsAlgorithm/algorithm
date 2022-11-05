function solution(array) {
  let result = 0;

  for (let i = 0; i < array.length; i++) {
    let element = array[i].toString();
    for (let j = 0; j < element[j]; j++) {
      let arrayElement = [...element[j]];
      for (let el of arrayElement) {
        if (el == "7") result++;
      }
    }
  }
  return result;
  // 다른 사람 풀이
  /* 배열을 문자열로 만들고 7를 기준으로 자른 배열의 길이 -1
  return array.join('').split('7').length-1;
  */
}
