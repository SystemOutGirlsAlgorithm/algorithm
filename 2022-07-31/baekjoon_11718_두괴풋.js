const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

function output(input) {
  let result = "";

  for (let i = 0; i < input.length; i++) {
    if (input.length > 100) {
      return;
    }

    if (input[i].length > 100) {
      return;
    }

    if (input[i].shift === " " || input[i].pop === " ") {
      return;
    }

    result += input[i] + "\n";
  }

  return console.log(result);
}

output(input);
