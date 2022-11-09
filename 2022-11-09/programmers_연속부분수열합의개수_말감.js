function solution(elements) {
  let answer = [];
  let elements2 = [...elements, ...elements];
  elements.map((el, index) => {
    let temp = 0;
    for (let i = index; i < index + elements.length; i++) {
      temp += elements2[i];
      answer.push(temp);
    }
  });
  answer = [...new Set(answer)];
  return answer.length;
}
