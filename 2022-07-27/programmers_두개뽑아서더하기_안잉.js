function solution(numbers) {
  var answer = [];
  for (let i = 0; i < numbers.length; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      let result = numbers[i] + numbers[j];
      const found = answer.find((v) => v === result);
      found === undefined ? answer.push(result) : null;
    }
  }
  return answer.sort((a, b) => a - b);
}
