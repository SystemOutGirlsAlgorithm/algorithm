function solution(k, tangerine) {
  let answer = 0;
  const store = new Map();
  tangerine.map((t) => {
    if (store.has(t)) {
      let temp = store.get(t);
      temp++;
      store.set(t, temp);
    } else store.set(t, 1);
  });
  const tangerineArr = [...store].sort((a, b) => b[1] - a[1]);
  let count = 0;
  for (let i = 0; i < tangerineArr.length; i++) {
    count += tangerineArr[i][1];
    answer++;
    if (count >= k) break;
  }
  return answer;
}
