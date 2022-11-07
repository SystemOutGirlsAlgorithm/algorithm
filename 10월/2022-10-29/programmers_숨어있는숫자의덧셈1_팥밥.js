function solution(my_string) {
  let answer = 0;

  // match함수를 사용해 숫자만 골라낸 배열을 생성 => 배열의 값을 reduce로 모두 더함
  // +cur인 이유는 문자열을 정수로 만들기 위한 것
  answer = my_string.match(/[0-9]/g).reduce((prev, cur) => prev + +cur, 0);

  return answer;
}
