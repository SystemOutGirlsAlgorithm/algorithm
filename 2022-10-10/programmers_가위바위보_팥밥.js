// 가위바위보를 숫자로 표현해서 결과 출력
// 매개변수 rsp를 배열로 쪼개서 각각 이기는 결과를 wins에 추가
function solution(rsp) {
  // 0은 2를 이김, 2는 5를 이김, 5는 0을 이김
  let wins = "";
  let rspArr = rsp.split("");

  for (let i = 0; i < rspArr.length; i++) {
    if (rspArr[i] == 0) wins += 5;
    else if (rspArr[i] == 2) wins += 0;
    else if (rspArr[i] == 5) wins += 2;
  }
  return wins;
  /* map 자료구조와 map 함수를 사용한 방법
  가위 바위 보 별로 내는 것을 키, 이기는 것을 밸류로 저장해두고 
  배열로 만든 rsp의 요소를 하나하나 불러와 arr의 키로 입력하고 
  그 모든 결과를 join함수를 사용해 문자열로 만든다.
  let arr = {
      2: 0,
      0: 5,
      5: 2
  };
  var answer = [...rsp].map(v => arr[v]).join("");
  return answer;
  */
}
