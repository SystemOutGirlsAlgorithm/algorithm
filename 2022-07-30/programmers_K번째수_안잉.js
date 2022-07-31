function solution(array, commands) {
  var answer = [];
  for (let i = 0; i < commands.length; i++) {
    let result = [];
    let current = [];
    for (let j = 0; j < 3; j++) {
      current.push(commands[i][j]);
    }
    result = array
      .slice(current[0] - 1, current[1])
      .sort((a, b) => a - b)
      .slice(current[2] - 1, current[2]);
    answer.push(result.join(""));
  }
  answer = answer.map((v) => Number(v));
  return answer;
}
