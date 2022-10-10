function solution(n) {
  // 정규식으로 1개수 카운트
  let nCount = n.toString(2).match(/1/g).length;

  // n을 1씩 증가시키면서 2진수일때 1 개수를 계속 체크
  while (true) {
    n++;
    if (n.toString(2).match(/1/g).length == nCount)
      // n은 이미 자연순데 parseInt(n,2)를 써서 오류 났었음(이런 실수 안하게 주의)
      return n;
  }
}
