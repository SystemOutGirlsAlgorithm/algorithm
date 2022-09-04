function solution(progresses, speeds) {
  const answer = [];
  let day = 0;
  progresses.map((progress, index) => {
    if (speeds[index] * day + progress >= 100) {
      answer[answer.length - 1] += 1;
    } else {
      day = Math.ceil((100 - progress) / speeds[index]);
      answer.push(1);
    }
  });
  return answer;
}
