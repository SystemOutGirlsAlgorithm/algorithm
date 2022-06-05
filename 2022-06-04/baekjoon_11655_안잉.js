const input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
const sentence = input[0];
let result = [];
let answer = [];

for (let i in sentence) {
  let currentAscii = sentence.charCodeAt(i);
  if (currentAscii >= 65 && currentAscii <= 90) {
    if (currentAscii >= 78) {
      result.push(currentAscii - 13);
    } else {
      result.push(currentAscii + 13);
    }
  } else if (currentAscii >= 97 && currentAscii <= 122) {
    if (currentAscii >= 110) {
      result.push(currentAscii - 13);
    } else {
      result.push(currentAscii + 13);
    }
  } else {
    result.push(currentAscii);
  }
}

for (let i in result) {
  answer.push(String.fromCharCode(result[i]));
}

console.log(answer.join(""));
