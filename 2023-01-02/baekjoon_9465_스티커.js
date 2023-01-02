//59. 9465 스티커
//해설: https://leylaoriduck.tistory.com/533

const question = `2
5
50 10 100 20 40
30 50 70 10 60
7
10 30 10 50 100 20 40
20 40 30 50 60 20 80`;
// 260
// 290

const fs = require('fs');

const inputs = (
  process.platform === 'linux'
    ? fs.readFileSync('/dev/stdin', 'utf8').toString()
    : question
).split('\n');

const T = Number(inputs.shift());

for (let i = 0; i < T; i++) {
  let n = inputs[i * 3];
  const up = inputs[i * 3 + 1].split(' ').map(Number);
  const down = inputs[i * 3 + 2].split(' ').map(Number);

  // console.log(n);
  // console.log(up);
  // console.log(down);
  const dp = [];
  dp[0] = [0, up[0], down[0]];

  for (let j = 1; j < n; j++) {
    dp[j] = [];
    dp[j][0] = Math.max(dp[j - 1][1], dp[j - 1][2]);
    dp[j][1] = up[j] + Math.max(dp[j - 1][0], dp[j - 1][2]);
    dp[j][2] = down[j] + Math.max(dp[j - 1][0], dp[j - 1][1]);
  }
  // console.log(dp);
  console.log(Math.max(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]));
}
