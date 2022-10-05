function solution(brown, yellow) {
  // 총 격자 개수
  let sum = brown + yellow;

  for (let height = 3; height <= brown; height++) {
    if (sum % height === 0) {
      //이 식이 성립해야 사각형
      let weight = sum / height;
      //가로 세로에서 -2를 하는 이유는 갈색 격자 가 위아래 양옆으로 한줄씩있어서
      if ((weight - 2) * (height - 2) === yellow) {
        return [weight, height];
      }
    }
  }
}
