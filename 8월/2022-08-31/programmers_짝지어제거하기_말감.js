function solution(s) {
  const stack = [];
  for (let tmp of s) {
    if (stack[stack.length - 1] === tmp) {
      stack.pop();
      continue;
    }
    stack.push(tmp);
  }
  return stack.length ? 0 : 1;
}
