// Q : left부터 right까지의 모든 수들 중에서, 약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수를 return 하도록 solution 함수

// 01. 공약수 구하는 함수
function divisor(number) {
  let numberOfdivisor = [];

  let i = 1;
  while (i <= number) {
    if (number % i === 0) {
      numberOfdivisor.push(i);
    }
    i++;
  }
  return numberOfdivisor.length;
 }

 
 // =========================================

// 02. 문제에 대한 답 
function solution(left, right) {
  var answer = 0; // 최종답

  for(let i=left; i<=right; i++){
    let count = divisor(i);
    if(count % 2 === 0){
      answer += i;
    } else {
      answer -= i;
    }
  }
  return answer;
}

console.log(solution(2, 7));