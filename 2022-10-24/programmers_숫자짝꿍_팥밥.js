// 일치하는 숫자의 개수를 조정하는 것을 못해서 다른 사람 코드 참고
function solution(X, Y) {
  var answer = "";

  X = [...X];
  Y = [...Y];

  for (let i = 0; i < 10; i++) {
    // 숫자가 0~9까지니까 i<10만큼 반복하면서 i와 값이 같은 것을 찾아서 각 길이를 측정하고
    // 둘 중에 더 작은 수만큼 answer에 반복해서 추가
    // 이렇게 하면 X,Y가 일치하지 않을때는 추가안되니까
    // 일치하는 것 추가한 다음 개수 조정을 하지 않아도 됨
    const X_cnt = X.filter((item) => +item === i).length;
    const Y_cnt = Y.filter((item) => +item === i).length;
    answer += i.toString().repeat(Math.min(X_cnt, Y_cnt));
  }

  // answer이 비어있으면 -1
  // 0으로만 차있으면 0
  // 그것도 아니면 가장 큰 숫자를 return
  if (answer === "") return "-1";
  else if (answer.match(/[^0]/g) === null) return "0";
  else return [...answer].sort().reverse().join("");
}
