// 소수 판별
function isDecimal(num) {
  if (num === 1 || num === 0) return false;
  const temp = parseInt(Math.sqrt(num));
  for (let i = 2; i < temp + 1; i++) {
    if (num % i === 0) return false;
  }
  return true;
}

// 순열
function permutaion(count, array) {
  const result = [];
  if (count === 1) return array.map((item) => [item]);

  array.map((number, index, origin) => {
    // number를 제외한 리스트
    const rest = [...array.slice(0, index), ...array.slice(index + 1)];
    const restPrmt = permutaion(count - 1, rest);
    const attach = restPrmt.map((el) => [number, ...el]);
    result.push(...attach);
  });
  return result;
}

function solution(numbers) {
  const nums = [...numbers];
  const prmt = [];
  for (let i = 1; i < nums.length + 1; i++) {
    prmt.push(...permutaion(i, nums));
  }
  const answer = prmt.filter((item) => isDecimal(+item.join("")));
  return [...new Set(answer.map((item) => +item.join("")))].length;
}
