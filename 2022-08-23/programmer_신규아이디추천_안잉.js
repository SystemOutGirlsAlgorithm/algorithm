function solution(new_id) {
  let answer = "";
  answer = new_id
    .toLowerCase()
    .replace(/[^0-9a-z._-]/g, "")
    .replace(/\.+/g, ".")
    .replace(/^\.|\.$/g, "")
    .replace(/^$/, "a")
    .slice(0, 15)
    .replace(/\.$/, "");
  if (answer.length <= 2) {
    while (answer.length !== 3) {
      answer += answer[answer.length - 1].repeat(1);
    }
  }
  return answer;
}
