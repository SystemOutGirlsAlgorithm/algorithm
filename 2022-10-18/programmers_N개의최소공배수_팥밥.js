/* 시간 초과
function solution(arr) {
  let lcm = 0;
  for(let i = 0; i < arr.length; i++){
      let temp = arr[i] * arr[i+1] / gcd(arr[i],arr[i+1]);
      if(temp > lcm) lcm = temp;
  }return lcm;
}

function gcd(a,b){
  let r;
  
  while(b > 0){
      r = a % b;
      a = b;
      b = r;
  }return a;
}
*/

// 다른 사람 풀이 최고공배수, 최대공약수 함수 따로 만듬
function solution(arr) {
  let answer = 0;

  answer = arr.reduce((a, b) => lcm(a, b), 1);

  return answer;
}

function gcd(a, b) {
  let r;

  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

function lcm(a, b) {
  return (a * b) / gcd(a, b);
}
