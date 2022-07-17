function solution(s) {
  let isP = 0;
  let isY = 0;
  s.split("").map((v) => {
    v === "p" || v === "P" ? isP++ : v === "y" || v === "Y" ? isY++ : null;
  });

  return isP === isY;
}
