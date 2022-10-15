function solution(s) {
  // notPairStack에 값을 하나씩 넣으면서 다음 요소랑 일치하면 삭제 아니면 유지를 반복
  let answer = 0;
  let notPairStack = [];
  notPairStack.push(s[0]);

  for (let i = 1; i < s.length; i++) {
    if (notPairStack[notPairStack.length - 1] === s[i]) {
      notPairStack.pop();
    } else {
      notPairStack.push(s[i]);
    }
  }
  // answer에 안 넣고 바로 삼항연산자로 return하면 케이스2에서 시간 초과
  // 길이가 0일때가 전부 없앨 수 있는거라서 1을 return 해야하는데 반대로 이해해서 계속 틀렸음
  answer = notPairStack.length === 0 ? 1 : 0;
  return answer;
}
