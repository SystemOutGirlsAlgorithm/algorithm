function solution(n, k) {
  let total = n * 12000 + k * 2000;
  // 양꼬치 10개 단위마다 음료 하나 할인해야 하는데 문제를 제대로 안 읽어서 계속 틀림
  return n >= 10 ? total - Math.floor(n / 10) * 2000 : total;
}
