function solution(numbers) {
  /* 실패 -> 인덱스 값이 다른 것들 끼리만 더해야함
  let sumArr = [];

  for(let i = 0; i < numbers.length; i++){
      for(let j = 0; j < numbers.length; j++){
          sumArr.push(numbers[i] + numbers[j]);
      }
  }
  let result = new Set(sumArr);

  return [...result].sort((a,b) => a-b);
  */
  // 다른 사람들 풀이랑 차이나는 점은 중복 제거하는 부분 forEach와 includes를 사용하거나 indexOf를 사용하는 경우가 많았음
  let sumArr = [];

  for (let i = 0; i < numbers.length; i++) {
    for (let j = 0; j < numbers.length; j++) {
      // 조건을 추가해서 해결
      if (i !== j) sumArr.push(numbers[i] + numbers[j]);
    }
  }
  let result = new Set(sumArr);

  return [...result].sort((a, b) => a - b);
}
