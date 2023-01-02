//56. RGB거리
// 정답 해설: https://tesseractjh.tistory.com/117

// const question = `3
// 26 40 83
// 49 60 57
// 13 89 99`;
// // 96

// const question = `3
// 1 100 100
// 100 1 100
// 100 100 1`;
// // 3

// const question = `3
// 1 100 100
// 100 100 100
// 1 100 100`;
// // 102

// const question = `6
// 30 19 5
// 64 77 64
// 15 19 97
// 4 71 57
// 90 86 84
// 93 32 91`;
// // 208

const question = `8
71 39 44
32 83 55
51 37 63
89 29 100
83 58 11
65 13 15
47 25 29
60 66 19`;
// 253

const fs = require('fs');

const inputs = (
  process.platform === 'linux'
    ? fs.readFileSync('/dev/stdin', 'utf8').toString()
    : question
).split('\n');

const N = Number(inputs[0]);
const rgb = inputs.map((str) => str.split(' ').map(Number));
const dp = [[0, 0, 0], []];

dp[1][0] = rgb[1][0];
dp[1][1] = rgb[1][1];
dp[1][2] = rgb[1][2];
// console.log(N);
// console.log(rgb);

for (let n = 2; n <= N; n++) {
  dp[n] = [];
  dp[n][0] = Math.min(dp[n - 1][1] + rgb[n][0], dp[n - 1][2] + rgb[n][0]);
  dp[n][1] = Math.min(dp[n - 1][0] + rgb[n][1], dp[n - 1][2] + rgb[n][1]);
  dp[n][2] = Math.min(dp[n - 1][0] + rgb[n][2], dp[n - 1][1] + rgb[n][2]);
}
// console.log(dp);

console.log(Math.min(dp[N][0], dp[N][1], dp[N][2]));
