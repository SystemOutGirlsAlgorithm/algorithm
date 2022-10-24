// 여는 괄호, 닫히는 괄호 짝이 맞는지 확인하는 부분을 못해서 다른 사람 풀이 참고
function solution(s) {
  const stack = [];
  let result = 0;
  let isRight = true;
  if (s.length % 2 === 1) return 0; // 문자열 길이가 홀수면 X

  for (let i = 0; i < s.length; i++) {
    // slice(i)는 i부터 끝까지 잘라냄
    // slice(0,i)는 0부터 i까지 잘라냄
    let candidate = s.slice(i) + s.slice(0, i);
    isRight = true;
    for (let word of candidate) {
      // s를 회전한 문자열 candidate를 한글자씩 확인할때 여는 괄호면 stack에 push
      if (word === "(" || word === "{" || word === "[") stack.push(word);
      // 닫히는 괄호면 stack.pop()을 하는데
      // word가 )이면 pop한 글자가 (여야 조건에 맞음
      // 만약 pop하는 문자와 짝이 안맞다면 isRight를 false로 반환하고 반복문 break
      else {
        let leftWord = stack.pop();
        if (word === ")" && leftWord === "(") continue;
        if (word === "}" && leftWord === "{") continue;
        if (word === "]" && leftWord === "[") continue;
        isRight = false;
        break;
      }
    }
    // for-of 반복문을 종료한 후 isRight가 true면 result + 1해줌
    if (isRight) result++;
  }
  // 모든 반복문이 종료된 후 result의 값을 반환
  return result;
}
