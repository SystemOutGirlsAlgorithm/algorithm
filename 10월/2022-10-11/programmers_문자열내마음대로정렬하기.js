function solution(strings, n) {
  // 못풀어서 다른 사람 풀이 참고
  return strings.sort((a, b) => {
    // 인덱스 n번째 글자를 기준으로 오름차순 정렬
    if (a[n] > b[n]) return 1;
    else if (a[n] < b[n]) return -1;
    // 인덱스 n번째 글자가 같으면 사전순 정렬
    else return a > b ? 1 : -1;
  });
  /* 다른 사람 풀이 sort와 localeCompare 함수 사용
  - localeCompare 함수는 문자열을 서로 비교하고 정렬 순서에 따른 값을 반환함(오름차순 -1, 내림차순 1, 같음 0)
  return strings.sort((s1, s2) => s1[n] === s2[n] ? s1.localeCompare(s2) : s1[n].localeCompare(s2[n]));
  */
}
