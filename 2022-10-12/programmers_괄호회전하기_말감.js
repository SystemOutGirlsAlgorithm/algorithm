function solution(s) {
  let doubles = s + s;
  let answer = 0;
  for (let i = 0; i < s.length; i++) {
    const stack = [];
    let check = true;
    for (let d of doubles.slice(i, i + s.length)) {
      if (["(", "[", "{"].includes(d)) stack.push(d);
      else {
        if (!["()", "[]", "{}"].includes(stack.pop() + d)) {
          check = false;
          break;
        }
      }
    }
    if (!stack.length && check) answer += 1;
  }
  return answer;
}
