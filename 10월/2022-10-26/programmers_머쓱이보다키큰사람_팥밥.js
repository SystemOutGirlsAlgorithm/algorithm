function solution(array, height) {
  return array.filter((el) => el > height).length;
}
