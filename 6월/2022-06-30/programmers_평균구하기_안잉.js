const solution = (arr) => {
  let answer = 0;
  answer = [...arr].reduce((p, c) => p + c);
  answer /= arr.length;
  return answer;
};
