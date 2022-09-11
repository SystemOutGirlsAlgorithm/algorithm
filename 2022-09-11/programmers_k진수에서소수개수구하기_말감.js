function convert(n, k, kNum) {
  if (n < 1) return kNum;
  return convert(parseInt(n / k), k, (n % k) + kNum);
}

function primeNumber(num) {
  if (num === 1) return false;
  for (let n = 3; n < Math.sqrt(num) + 1; n++) {
    if (num % n === 0) return false;
  }
  return true;
}

function solution(n, k) {
  // k진수로 변환
  const convertK = convert(n, k, "");
  let answer = 0;
  convertK.split("0").map((number) => {
    if (number && primeNumber(+number)) answer += 1;
  });
  return answer;
}
