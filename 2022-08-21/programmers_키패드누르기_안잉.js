function solution(numbers, hand) {
  let answer = "";
  let currentLeft = 10;
  let currentRight = 12;

  for (let i = 0; i < numbers.length; i++) {
    let currentNum = numbers[i];
    if (currentNum === 0) {
      currentNum = 11;
    }
    if (currentNum % 3 === 1) {
      pressLeft(currentNum);
    } else if (currentNum % 3 === 0) {
      pressRight(currentNum);
    } else {
      let lValue = 0;
      let rValue = 0;
      let lCopy = currentLeft;
      let rCopy = currentRight;
      if (lCopy % 3 !== 2) {
        lValue++;
        lCopy += 1;
      }
      if (lCopy !== currentNum) {
        while (lCopy !== currentNum) {
          if (lCopy > currentNum) {
            lCopy -= 3;
          } else {
            lCopy += 3;
          }
          lValue++;
        }
      }
      if (rCopy % 3 !== 2) {
        rValue++;
        rCopy -= 1;
      }
      if (rCopy !== currentNum) {
        while (rCopy !== currentNum) {
          if (rCopy > currentNum) {
            rCopy -= 3;
          } else {
            rCopy += 3;
          }
          rValue++;
        }
      }
      if (lValue === rValue) {
        if (hand === "left") {
          pressLeft(currentNum);
        } else {
          pressRight(currentNum);
        }
      } else if (lValue > rValue) {
        pressRight(currentNum);
      } else {
        pressLeft(currentNum);
      }
    }
  }
  return answer;

  function pressLeft(num) {
    currentLeft = num;
    answer += "L";
  }

  function pressRight(num) {
    currentRight = num;
    answer += "R";
  }
}
