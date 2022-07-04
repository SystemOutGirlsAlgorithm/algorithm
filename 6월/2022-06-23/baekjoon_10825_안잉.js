const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
const [, ...array] = input;
let answer = "";

const compare = (a, b) => {
  const studentA = a.split(" ").map((v) => Number(v) || v);
  const studentB = b.split(" ").map((v) => Number(v) || v);
  if (studentA[1] === studentB[1]) {
    if (studentA[2] === studentB[2]) {
      if (studentA[3] === studentB[3]) {
        if (studentA[0] > studentB[0]) return 1;
        else if (studentA[0] < studentB[0]) return -1;
      } else {
        return studentB[3] - studentA[3];
      }
    } else {
      return studentA[2] - studentB[2];
    }
  } else {
    return studentB[1] - studentA[1];
  }
};

array.sort(compare);

for (let i in array) {
  answer += `${array[i].split(" ")[0]}\n`;
}

console.log(answer.trim());
