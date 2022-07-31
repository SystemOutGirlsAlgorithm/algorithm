function solution(answers) {
  const stud1 = [1, 2, 3, 4, 5];
  const stud1Length = stud1.length;
  const stud2 = [2, 1, 2, 3, 2, 4, 2, 5];
  const stud2Length = stud2.length;
  const stud3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
  const stud3Length = stud3.length;
  let correct = [0, 0, 0];
  var answer = [];

  for (let i = 0, len = answers.length; i < len; i++) {
    if (answers[i] === stud1[i % stud1Length]) correct[0]++;
    if (answers[i] === stud2[i % stud2Length]) correct[1]++;
    if (answers[i] === stud3[i % stud3Length]) correct[2]++;
  }

  const maxResult = Math.max(...correct);
  for (let i = 1; i <= 3; i++) {
    if (maxResult === correct[i - 1]) answer.push(i);
  }
  return answer;
}
