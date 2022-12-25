//58. 오르막 수
// 정답해설: https://leylaoriduck.tistory.com/532
// const question = `1`;
// // 10
const question = `2`;
// 55
// const question = `3`;
// // 220

const fs = require('fs');

const inputs = (
  process.platform === 'linux'
    ? fs.readFileSync('/dev/stdin', 'utf8').toString()
    : question
).split('\n');
// 10_007
const N = Number(inputs[0]);
//10 9 8 ... 1
const dp = [[], Array(10).fill(1)];

for (let n = 2; n <= N; n++) {
  dp[n] = [];
  dp[n][0] = 1;
  for (let p = 1; p < 10; p++) {
    dp[n][p] = (dp[n - 1][p] + dp[n][p - 1]) % 10_007;
  }
}

const result = dp[N].reduce((acc, cur) => (acc += cur), 0);

console.log(result % 10_007);
