// 해결 못해서 다른 사람 풀이 참고
// skill_trees[i].includes(skillArr[i])로 생각하니까 계속 답이 안나온듯
function solution(skill, skill_trees) {
  // 문자열 잘라서 배열로 만듬
  let skillArr = skill.split("");
  let str = 0;
  let count = 0;

  // 반복문 돌면서 skill_trees의 요소를 하나씩 잘라 skillArr에 포함되는지 확인하고 포함되는 것만 join해서 문자열 str형성
  // 그 문자열이 skill을 str 길이만큼 잘라낸 것과 일치하면 count++
  for (let i = 0; i < skill_trees.length; i++) {
    str = skill_trees[i]
      .split("")
      .filter((v) => skillArr.includes(v))
      .join("");
    if (str === skill.substring(0, str.length)) {
      count++;
    }
  }
  return count;
}
