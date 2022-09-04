function solution(priorities, location) {
  let answer = 1;
  const document = priorities.map((el, index) => [el, index]);
  while (true) {
    const maxArr = document.slice(1).filter((el) => el[0] > document[0][0]);
    const temp = document.shift();
    if (maxArr.length) document.push(temp);
    else {
      if (temp[1] === location) break;
      answer += 1;
    }
  }
  return answer;
}
