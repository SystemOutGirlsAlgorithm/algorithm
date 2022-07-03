const solution = (x) => {
  let answer = true;
  const arr = String(x)
    .split("")
    .map((v) => Number(v));
  const sum = [...arr].reduce((p, c) => p + c);
  answer = x % sum === 0 ? true : false;
  return answer;
};
