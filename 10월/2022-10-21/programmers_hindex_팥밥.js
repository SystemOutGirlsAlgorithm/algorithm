function solution(citations) {
  /* 테스트 케이스 9번에서 오류
  let answer = [];

  citations.sort((a,b) => b-a);

  for(let i = 0; i < citations.length; i++){
      if(i >= citations[i]) answer.push(i)
  }

  return answer.length > 0 ? answer[0] : 0;*/

  let i = 0;

  citations = citations.sort((a, b) => b - a);

  // i > citations[i]가 되는 순간 반복문 종료하고 i값 return
  while (i + 1 <= citations[i]) {
    i++;
  }
  return i;

  // 다른 사람 풀이
  // citations.sort((a, b) => b - a).filter((el, idx) => el >= idx + 1).length;
}
