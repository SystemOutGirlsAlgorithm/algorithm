function solution(numbers) {
  // 배열 전체의 값을 더할 수 있는 reduce를 이용해서 평균을 구함
  return numbers.reduce((prev, cur) => prev + cur) / numbers.length;
}
