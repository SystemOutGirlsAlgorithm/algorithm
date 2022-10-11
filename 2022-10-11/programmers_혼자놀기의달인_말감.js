function solution(cards) {
  let answer = 0;
  for (let i = 1; i < cards.length + 1; i++) {
    const cardsCopy = [...cards];
    let num = i;
    const box1 = [],
      box2 = [];
    while (cardsCopy[num - 1] !== 0) {
      const temp = cardsCopy[num - 1];
      box1.push(temp);
      cardsCopy[num - 1] = 0;
      num = temp;
    }
    if (cardsCopy.filter((el) => el !== 0).length === 0) continue;
    num = i;
    while (cardsCopy[num - 1] !== -1) {
      if (cardsCopy[num - 1] == undefined) break;
      if (cardsCopy[num - 1] === 0) {
        if (box2.length === 0) {
          num++;
          continue;
        }
        break;
      }
      const temp = cardsCopy[num - 1];
      box2.push(temp);
      cardsCopy[num - 1] = -1;
      num = temp;
    }
    answer = Math.max(answer, box1.length * box2.length);
  }
  return answer;
}
