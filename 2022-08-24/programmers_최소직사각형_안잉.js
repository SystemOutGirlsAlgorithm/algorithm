function solution(sizes) {
  let answer = 0;
  let row = [];
  let column = [];
  for (let i = 0; i < sizes.length; i++) {
    if (sizes[i][0] < sizes[i][1]) {
      [sizes[i][0], sizes[i][1]] = [sizes[i][1], sizes[i][0]];
    }
    column.push(sizes[i][0]);
    row.push(sizes[i][1]);
  }
  answer = Math.max(...row) * Math.max(...column);
  return answer;
}
