const input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
let result = "";

for (let i in input) {
  if (input[i] === "") continue;
  const sentence = input[i].split("");
  const answer = new Array(4).fill(0);

  for (let j in sentence) {
    if (sentence[j] >= "a" && sentence[j] <= "z") {
      answer[0]++;
    } else if (sentence[j] >= "A" && sentence[j] <= "Z") {
      answer[1]++;
    } else if (sentence[j] >= "0" && sentence[j] <= "9") {
      answer[2]++;
    } else if (sentence[j] === " ") {
      answer[3]++;
    }
  }
  result += answer.join(" ") + "\n";
}
console.log(result.trim());
