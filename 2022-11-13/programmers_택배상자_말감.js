function solution(order) {
  const belt = [];
  let index = 0;
  for (let i = 1; i < order.length + 1; i++) {
    belt.push(i);
    while (belt.length > 0 && order[index] === belt[belt.length - 1]) {
      belt.pop();
      index++;
    }
  }
  return index;
}
