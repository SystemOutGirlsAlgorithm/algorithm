/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  const map = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
  };
  let countNumber = 0;

  // IV = 4 같은 경우를 해결할 방법을 몰라서 다른 사람 코드 참고
  // map[s[i]]와 map[s[i+1]]의 값을 비교해서 map[s[i]]가 더 작으면 그 수만큼 빼는 방법 사용
  for (let i = 0; i < s.length; i++) {
    if (i + 1 < s.length && map[s[i]] < map[s[i + 1]]) countNumber -= map[s[i]];
    else countNumber += map[s[i]];
  }

  /* 실패한 코드
  for(let i = 0; i < s.length; i++){
      if(s[i] === "I") countNumber += 1;
      if(s[i] === "V") countNumber += 5;
      if(s[i] === "X") countNumber += 10;
      if(s[i] === "L") countNumber += 50;
      if(s[i] === "C") countNumber += 100;
      if(s[i] === "D") countNumber += 500;
      if(s[i] === "M") countNumber += 1000;
  }*/
  return countNumber;
};
