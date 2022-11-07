// 해결 방법을 못찾아서 한참 못 풀었는데 힌트로 2진수 변환했을때 1의 갯수라고해서 풀게됨
// 문제를 다양하게 접근하는 것도 중요한듯
function solution(n) {
  return n
    .toString(2)
    .split("")
    .filter((v) => v == "1").length;
}
