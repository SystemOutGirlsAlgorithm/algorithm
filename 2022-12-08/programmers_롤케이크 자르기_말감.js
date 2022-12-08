function solution(topping) {
  const temp = new Map();
  topping.map((el) => {
    if (temp.has(el)) {
      const tmptopping = temp.get(el);
      tmptopping.count++;
      temp.set(el, tmptopping);
    } else {
      temp.set(el, { count: 1, visited: false });
    }
  });
  let answer = 0;
  let [old, young] = [0, temp.size];

  for (let i = 0; i < topping.length; i++) {
    const topval = temp.get(topping[i]);
    if (topval.count >= 1) {
      topval.count--;
      if (topval.count === 0) young--;
    }
    if (!topval.visited) {
      topval.visited = true;
      old++;
    }
    temp.set(topping[i], topval);
    if (old === young) answer++;
  }
  return answer;
}
