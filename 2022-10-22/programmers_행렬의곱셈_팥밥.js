function solution(arr1, arr2) {
  let answer = [];

  // 너무 어려움.. 다른 사람 풀이 참고함...
  for (let i = 0; i < arr1.length; i++) {
    let arr = arr1[i];
    answer.push([]);
    for (let j = 0; j < arr2[0].length; j++) {
      let sum = 0;
      for (let z = 0; z < arr2.length; z++) {
        sum += arr[z] * arr2[z][j];
      }
      answer[i].push(sum);
    }
  }

  // 다른 사람 풀이, 이걸 어떻게 생각해냄...?
  // return arr1.map(row => arr2[0].map((x,y)=>row.reduce((a,b,c)=>a+b*arr2[c][y],0)));
  return answer;
}
