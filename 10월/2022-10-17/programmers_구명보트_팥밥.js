function solution(people, limit) {
  let answer = 0;
  let left = 0;
  let right = people.length - 1;

  people.sort((a, b) => b - a);

  // 왼쪽 = 가장 큰 수, 오른쪽 = 가장 작은 수
  // left가 right보다 작을 동안 반복
  while (left < right) {
    // 두 사람의 몸무게의 합이 limit을 초과하면 left만 태움
    // 초과하지 않으면 right도 같이 태우고 두 경우 모두 보트는 이동
    if (people[left] + people[right] > limit) {
      left++;
    } else {
      left++;
      right--;
    }
    answer++;
  }
  // 만약 남아있는 사람이 있다면
  // 즉, left와 right의 값이 같은 경우로 반복문이 끝나면
  // 또 보트 한번 이동
  if (left === right) answer++;

  return answer;
}
