function solution(citations) {
  citations.sort((a, b) => b - a);
  let answer = 0;
  while (answer + 1 <= citations[answer]) {
    answer += 1;
  }
  return answer;
}
