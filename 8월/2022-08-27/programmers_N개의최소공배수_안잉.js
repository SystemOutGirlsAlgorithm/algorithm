function solution(arr) {
  var answer = 0;

  const gcd = (i, j) => {
    if (j === 0) {
      return i;
    }
    return gcd(j, i % j);
  };

  const lcd = (i, j) => {
    return (i * j) / gcd(i, j);
  };

  answer = arr.reduce((a, b) => lcd(a, b), 1);
  return answer;
}
