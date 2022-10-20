function solution(array, n) {
  // filter함수를 사용해 array의 요소가 n과 같은 값을 가지는 것만 남기고 그 배열의 길이를 반환
  let answer = array.filter((el) => el === n).length;

  return answer;
}
