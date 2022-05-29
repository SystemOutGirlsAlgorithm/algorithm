const input = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ");

const a = BigInt(input[0]);
const b = BigInt(input[1]);

const gcd = (i, j) => {
  if (j === 0n) {
    return i;
  }
  return gcd(j, i % j);
};

const gcdResult = a > b ? gcd(a, b) : gcd(b, a);

console.log("1".repeat(gcdResult.toString()));
