function solution(lottos, win_nums) {
  let zero_sum = 0;
  let result = [];
  let answer = [];
  for (let i = 0; i < win_nums.length; i++) {
    const found = lottos.filter((num) => num === win_nums[i]);
    if (found.length > 0) {
      result.push(found);
    }
  }
  lottos.forEach((v) => {
    if (v === 0) {
      zero_sum++;
    }
  });

  zero_sum === 0 && result.length === 0 ? answer.push(6) : answer.push(7 - (result.length + zero_sum));
  result.length === 0 ? answer.push(6) : answer.push(7 - result.length);
  return answer;
}
