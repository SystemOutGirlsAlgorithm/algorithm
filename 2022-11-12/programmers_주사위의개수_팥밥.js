function solution(box, n) {
  let result = 1;

  for (let i = 0; i < box.length; i++) {
    result *= Math.floor(box[i] / n);
  }
  return result;
}
