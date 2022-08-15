function solution(n, lost, reserve) {
  var answer = 0;
  const studentsClothes = new Array(n + 1).fill(1);
  for (let student of lost) {
    studentsClothes[student] -= 1;
  }
  for (let student of reserve) {
    studentsClothes[student] += 1;
  }
  for (let i = 1; i <= studentsClothes.length; i++) {
    if (studentsClothes[i] === 0) {
      if (studentsClothes[i - 1] === 2 || studentsClothes[i + 1] === 2) {
        if (studentsClothes[i - 1] === 2) {
          studentsClothes[i - 1] -= 1;
          studentsClothes[i]++;
        } else {
          studentsClothes[i + 1] -= 1;
          studentsClothes[i]++;
        }
      }
    }
  }
  for (let attendStudent of studentsClothes) {
    answer += attendStudent > 0 ? 1 : 0;
  }
  return answer - 1;
}
