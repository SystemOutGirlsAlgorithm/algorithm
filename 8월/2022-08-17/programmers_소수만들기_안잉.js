function solution(nums) {
  var answer = 0;
  nums.sort((a, b) => a - b);
  const max = nums[nums.length - 1] + nums[nums.length - 2] + nums[nums.length - 3];
  const prime = [];

  // 에라토스테네스의 체
  const isPrime = new Array(max + 1).fill(true);
  isPrime[0] = false;
  isPrime[1] = false;
  for (let i = 2; i <= Math.ceil(Math.sqrt(max)); i++) {
    if (isPrime[i]) {
      for (let j = 2; j <= max / i; j++) {
        isPrime[j * i] = false;
      }
    }
  }

  // 소수 추출
  isPrime.forEach((v, i) => {
    if (v) {
      prime.push(i);
    }
  });

  // 경우의 수
  for (let i = 0; i <= nums.length; i++) {
    for (let j = i + 1; j <= nums.length; j++) {
      for (let k = j + 1; k <= nums.length; k++) {
        const result = nums[i] + nums[j] + nums[k];
        prime.forEach((v) => {
          if (v === result) {
            answer++;
          }
        });
      }
    }
  }
  return answer;
}
