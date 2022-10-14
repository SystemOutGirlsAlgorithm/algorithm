// 틀림
/*
function solution(dirs) {
  let dirsArr = dirs.split("");// 이동 명령을 하나씩 자르기
  let x = 0, y = 0; // 이동 좌표
  let direction = []; // 이동 좌표들을 기록

  for(let i = 0; i < dirsArr.length; i++){
      if(dirsArr[i] == "U") x++;
      else if(dirsArr[i] == "D") x--;
      else if(dirsArr[i] == "R") y++;
      else if(dirsArr[i] == "L") y--;
      direction.push([x,y])
  }

  // 중복 값 없애기
  // 2차원 배열을 |를 기준으로 1차원 배열로 만들고 set으로 중복 제거한 것을 다시 2차원 배열로
  let newDirec = [...new Set(direction.join("|").split("|"))]
  .map((v) => v.split(","))
  .map((v) => v.map((a) => +a));

  // 명령어의 길이 - 중복 제거 배열의 길이가 0이면 중복없이 이동, 아니면 중복을 제거한 배열의 길이
  return dirs.length - newDirec.length === 0 ? dirs.length : newDirec.length;
}
*/

//다른 사람 풀이 참고
function solution(dirs) {
  var answer = 0;
  let p = [0, 0]; // p[0] : x, p[1] : y
  const visit = []; // 방문 좌표 저장할 배열 선언

  for (let i of dirs) {
    const cur_p = p.slice(); // 배열 깊은 복사

    // 범위 체크 후 i에 따라 x, y +-
    if (i == "U" && p[1] < 5) p[1]++;
    else if (i == "D" && p[1] > -5) p[1]--;
    else if (i == "R" && p[0] < 5) p[0]++;
    else if (i == "L" && p[0] > -5) p[0]--;

    const st = p.join("") + cur_p.join(""); // 현재좌표+이동할좌표로 join 함수 사용하여 배열 문자열로 합치기
    const nd = cur_p.join("") + p.join(""); // 이동할좌표+현재좌표로 join 함수 사용하여 배열 문자열로 합치기

    // visit 배열에 st나 nd 포함할 경우 방문한 좌표이므로 패스 또는 st와 nd가 같으면 이동한 게 아니라 패스
    if (!visit.includes(st) && st != nd) {
      visit.push(st);
      visit.push(nd);
    } // 코드해석 하면서 생각한 건 두 값 모두 저장해야하나...? 이다...
  }
  answer = visit.length / 2;
  return answer;
}
