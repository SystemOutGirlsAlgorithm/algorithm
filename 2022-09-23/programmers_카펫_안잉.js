function solution(brown, yellow) {
  var answer = [];
  let row = 0;
  let col = 2;
  for (let i = 1; i <= brown / 4; i++) {
    col++;
    row = (brown - i * 2) / 2;
    let mid = i * (row - 2);
    if (mid === yellow) {
      answer.push(row, col);
      break;
    }
  }
  return answer;
}
