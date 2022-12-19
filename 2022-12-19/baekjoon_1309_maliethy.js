//57. 동물원
// 정답 해설: https://mygumi.tistory.com/128
const question = `4`;
// 41

const fs = require('fs');

const inputs = (
  process.platform === 'linux'
    ? fs.readFileSync('/dev/stdin', 'utf8').toString()
    : question
).split('\n');

const N = Number(inputs[0]);

const dp = [[], [1, 1, 1]];
for (let i = 2; i <= N; i++) {
  dp[i] = [0, 0, 0];
  dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
  dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
  dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
}

// console.log('dp', dp);
console.log((dp[N][0] + dp[N][1] + dp[N][2]) % 9901);
