function solution(board, moves) {
  let answer = 0;
  const arr = [];
  let bucket = [];
  for (let i = 0; i < board.length; i++) {
    let temp = [];
    for (let j = 0; j < board[i].length; j++) {
      temp.push(board[j][i]);
    }
    arr.push(temp);
  }

  for (let i = 0; i < moves.length; i++) {
    const found = arr[moves[i] - 1].find((v) => v > 0);
    if (found !== undefined) bucket.push(found);
    const foundIndex = arr[moves[i] - 1].findIndex((v) => v > 0);
    if (foundIndex !== -1) arr[moves[i] - 1][foundIndex] = 0;
    if (bucket.length !== 0 && bucket[bucket.length - 1] === bucket[bucket.length - 2]) {
      answer += 2;
      bucket.pop();
      bucket.pop();
    }
  }
  return answer;
}
