function solution(sizes) {
  let answer = 0;
  let idxW = [];
  let idxH = [];

  for (let i = 0; i < sizes.length; i++) {
    sizes[i].sort((a, b) => a - b);
  }
  idxW = sizes.map((e) => e[0]); // 인덱스가 0인 것만 모은 배열
  idxH = sizes.map((e) => e[1]); // 인덱스가 1인 것만 모은 배열

  // 가로 세로 최대 값을 곱한 값이 최소 직사각형의 크기
  answer = Math.max(...idxW) * Math.max(...idxH);

  return answer;
}
