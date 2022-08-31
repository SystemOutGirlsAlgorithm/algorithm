function solution(people, limit) {
  people.sort((a, b) => a - b);
  let answer = 0;
  let boat = 0;
  while (people.length > 0) {
    let person = people.pop();
    if (person + people[0] <= limit) {
      people.shift();
    }
    answer += 1;
  }
  return answer;
}
