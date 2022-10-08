function solution(array, commands) {
  // 계속 null값 들어가는 오류 발생 => 배열은 0부터 시작해서 n번째를 할때 -1을 해줘야함
  let result = [];

  for (let i = 0; i < commands.length; i++) {
    let tmp = [];
    tmp = array.slice(commands[i][0] - 1, commands[i][1]).sort((a, b) => a - b);
    result.push(tmp[commands[i][2] - 1]);
  }
  return result;
}
