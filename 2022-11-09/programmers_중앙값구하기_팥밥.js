function solution(array) {
  let center = Math.floor(array.length / 2);
  array.sort((a, b) => a - b);
  return array[center];
}
