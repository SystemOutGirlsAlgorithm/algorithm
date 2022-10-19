function solution(number) {
  let sum = 0;

  // number의 요소 3개를 중복되지 않게 더한 값이 0이면 sum++해서 마지막에 sum을 반환
  for (let i = 0; i < number.length; i++) {
    for (let j = i + 1; j < number.length; j++) {
      for (let k = j + 1; k < number.length; k++) {
        if (number[i] + number[j] + number[k] === 0) sum++;
      }
    }
  }
  return sum;
}
