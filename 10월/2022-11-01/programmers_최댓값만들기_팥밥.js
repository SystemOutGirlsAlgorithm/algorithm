function solution(numbers) {
  // 내 풀이 : 두 개씩 곱한 값을 result에 저장하고 그 중 가장 큰 수를 return
  /*
  let result = [];

  for (let i = 0; i < numbers.length; i++) {
    if (i + 1 < numbers.length) {
      result.push(numbers[i] * numbers[i + 1]);
    }
  }
  return Math.max(...result);
  */
  // 다른 사람 풀이 : 내림차순으로 정렬하고 가장 큰 값 * 그 다음으로 큰 값
  numbers.sort((a, b) => b - a);
  return numbers[0] * numbers[1];
}
