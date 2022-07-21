const solution = (a, b) => {
  let answer = "";
  let count = b;
  const day = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
  const month = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
  for (let i = 1; i < a; i++) count += month[i];
  answer = day[(count + 4) % 7];
  return answer;
};
