function solution(s) {
  var answer = [];
  let x = s;
  let zeroCount = 0;
  let count = 0;

  while (x !== "1") {
    count++;
    zeroCount += x.split("").filter((v) => v === "0").length;
    x = x.split("0").join("").length;
    x = x.toString(2);
  }

  answer.push(count, zeroCount);
  return answer;
}
