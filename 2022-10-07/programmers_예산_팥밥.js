function solution(d, budget) {
  // 주어진 배열d를 오름차순으로 정렬해서 하나씩 더하고 예산을 초과하면 마지막으로 더한 요소 빼기
  // 내 풀이
  let answer = 0,
    sum = 0;
  d.sort((a, b) => a - b);

  for (let i = 0; i < d.length; i++) {
    answer++;
    sum += d[i];

    if (sum > budget) answer--;
  }

  return answer;
  // 다른 사람 풀이
  /* 코드는 이게 깔끔한데 반복할때마다 reduce에 pop까지 계속해야되서 효율은 떨어진다 함
  오름차순으로 정렬한 d의 값을 전체적으로 더한다음(reduce), 그 값이 예산을 초과하면 pop하는 과정을 예산을 초과하지 않을때까지 반복
  d.sort((a, b) => a - b);

    while (d.reduce((a, b) => (a + b), 0) > budget) d.pop();

    return d.length;
  */
}
