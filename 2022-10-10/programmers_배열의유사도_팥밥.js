// 간단하게 생각해서 s1과 s2를 하나하나 비교하고 일치하는 갯수를 return
function solution(s1, s2) {
  let count = 0;

  for (let i = 0; i < s1.length; i++) {
    for (let j = 0; j < s2.length; j++) {
      if (s1[i] == s2[j]) count++;
    }
  }
  return count;
  /* filter함수와 includes를 사용한 다른 사람 풀이
  여전히 filter나 map 함수를 사용하는게 어색함. 더 공부 필요
  let some = s1.filter(x => s2.includes(x));

  return some.length;
  */
}
