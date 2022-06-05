const input = require("fs").readFileSync("/dev/stdin").toString().trim().split(" ");

const getPrime = (n) => {
  let divider = 2;
  while (n != 1) {
    if (n % divider === 0) {
      console.log(divider);
      n /= divider;
    } else {
      divider++;
    }
  }
};

getPrime(Number(input[0]));
