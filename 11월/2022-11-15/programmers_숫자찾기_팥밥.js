function solution(num, k) {
  // "" + num를 통해서 정수 num을 문자열로 만들고 그걸 [...]로 감싸서 배열로 만들어줌
  // findIndex함수를 사용해서 n과 k의 값이 같은 경우를 찾는데 +n을 하는 이유는 n을 정수로 만들기 위해서임
  // findIndex의 결과가 -1이면 -1 반환 아니면 결과에 1을 더한 값을 출력
  const indexNum = [...("" + num)].findIndex((n) => +n === k);
  return indexNum === -1 ? -1 : indexNum + 1;
}
