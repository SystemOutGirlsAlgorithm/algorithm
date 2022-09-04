function solution(numbers) {
  let answer = 0;
  const arr = new Array(10).fill(false);
  numbers.forEach((v) => (arr[v] = true));
  arr.forEach((v, i) => {
    if (!v) answer += i;
  });
  return answer;
}
