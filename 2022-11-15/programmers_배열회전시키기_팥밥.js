function solution(numbers, direction) {
  let result = [];

  if (direction === "right") {
    let poped = numbers.pop();

    result.push(poped);
    for (let i = 0; i < numbers.length; i++) {
      result.push(numbers[i]);
    }
  } else {
    let shifted = numbers.shift();

    for (let i = 0; i < numbers.length; i++) {
      result.push(numbers[i]);
    }
    result.push(shifted);
  }

  return result;
}
