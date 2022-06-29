const solution = (n, m) => {
  var answer = [];
  const gcd = (i, j) => {
    if (j === 0) {
      return i;
    }
    return gcd(j, i % j);
  };

  const gcdResult = gcd(n, m);
  const lcdResult = (n * m) / gcdResult;

  answer.push(gcdResult, lcdResult);
  return answer;
};

console.log(solution(2, 5));
