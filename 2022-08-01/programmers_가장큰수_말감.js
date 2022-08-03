function solution(numbers) {
  numbers = numbers.map((num) => num + "");
  numbers = numbers.sort((a, b) => b + a - (a + b));
  return numbers[0] === "0" ? "0" : numbers.join("");
}
