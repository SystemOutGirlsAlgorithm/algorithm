function solution(n, words) {
  /* 끝말잇기가 성립안되는 경우를 못 잡아냄, 반복되는 단어를 말하는 경우도 오류 발생
  let failPerson = 0;
  let failNumber = 0;
  let count = 0;

  for(let i = 0; i < words.length; i++){
      if(words.includes(words[i])){
        count++;
        if(count > 1){
            failPerson = (i+1) / n;
            failNumber = (i+1) % n===0 ? n : (i+1) % n;
            break;
        }
      }
  }
  return [failNumber,failPerson]
  */

  // 다른 사람 풀이 참고
  let answer = 0;

  words.reduce((prev, now, idx) => {
    answer =
      answer ||
      (words.slice(0, idx).indexOf(now) !== -1 || prev !== now[0]
        ? idx
        : answer);
    return now[now.length - 1];
  }, "");

  return answer ? [(answer % n) + 1, Math.floor(answer / n) + 1] : [0, 0];
}
