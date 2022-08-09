function solution(N, stages) {
  var answer = [];
  let stage = new Array(N).fill(0);
  let remain = stages.length;
  let result = [];
  stages.forEach((v) => {
    if (v <= N) {
      stage[v - 1]++;
    }
  });
  stage.forEach((v) => {
    console.log(v, remain);
    if (isNaN(v / remain)) {
      result.push(0);
    } else {
      result.push(v / remain);
    }
    remain -= v;
  });

  console.log(result);
  while (answer.length < N) {
    let found = Math.max(...result);
    answer.push(result.indexOf(found) + 1);
    result[result.indexOf(found)] = -1;
  }

  return answer;
}
