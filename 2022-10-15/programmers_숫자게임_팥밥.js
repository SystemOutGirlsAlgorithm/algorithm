function solution(A, B) {
  let score = 0;
  let left = 0;

  // 두 배열을 오름차순으로 정렬
  A.sort((a, b) => a - b);
  B.sort((a, b) => a - b);

  // 근소한 차이로 점수 차이가 나야 최고 점을 얻을 수 있어서 작은 수부터 차례로 비교해야 유리함
  for (let i = 0; i < B.length; i++) {
    if (A[left] < B[i]) {
      // 비교해서 B[i]가 더 크면 점수를 1점 추가하고 다음 A값으로 넘어감
      left++;
      score++;
    }
  }

  return score;
}
