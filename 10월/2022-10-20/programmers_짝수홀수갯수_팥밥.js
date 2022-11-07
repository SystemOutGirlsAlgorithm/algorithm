function solution(num_list) {
  // 2로 나눴을 때 나머지가 0이면 짝수 아니면 홀수
  let odd = num_list.filter((v) => v % 2 !== 0).length;
  let even = num_list.filter((v) => v % 2 === 0).length;

  return [even, odd];
}
