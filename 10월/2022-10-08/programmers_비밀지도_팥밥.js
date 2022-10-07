// 해결 못해서 다른 사람 풀이 참고
//방법 : map을 사용해서 각 배열 a와 b를 2진수로 만들고
// padStart로 n만큼 0으로 채워둠(빈칸을 채움)
// replace와 정규식을 사용해서 0은 공백으로 1은 #으로 바꿈
var solution = (n, a, b) =>
  a.map((a, i) =>
    (a | b[i]).toString(2).padStart(n, 0).replace(/0/g, " ").replace(/1/g, "#")
  );
