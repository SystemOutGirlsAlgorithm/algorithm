function solution(s) {
  s = s.slice(2, s.length - 2).split("},{");
  s = s.map((item) => item.split(",").map(Number));
  s = s.sort((a, b) => a.length - b.length);
  const answer = [];
  s.map((num) => answer.push(...num));
  return [...new Set(answer)];
}
