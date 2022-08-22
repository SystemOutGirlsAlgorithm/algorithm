function solution(s) {
  let answer = 0;
  let result = "";
  let temp = [];
  const numberString = {
    zero: 0,
    one: 1,
    two: 2,
    three: 3,
    four: 4,
    five: 5,
    six: 6,
    seven: 7,
    eight: 8,
    nine: 9,
  };

  for (let i = 0; i < s.length; i++) {
    if (Number.isNaN(parseInt(s[i]))) {
      temp.push(s[i]);
      for (let property in numberString) {
        if (temp.join("") === property) {
          temp = [];
          result += numberString[property];
        }
      }
    } else {
      result += s[i];
    }
  }
  answer = parseInt(result);
  return answer;
}
