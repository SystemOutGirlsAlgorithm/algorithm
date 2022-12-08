function solution(my_string) {
  // 아스키코드로 구별해서 65이상이면서 97미만이면 소문자로 아니면 대문자로
  return [...my_string]
    .map((a) =>
      a.charCodeAt() >= 65 && a.charCodeAt() < 97
        ? a.toLowerCase()
        : a.toUpperCase()
    )
    .join("");
}
