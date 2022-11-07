// 처음에 소수점 밑으로 버리라는 문구를 못봐서 틀림(문제 꼼꼼히 읽기)
function solution(price) {
  if (price >= 100000 && price < 300000) return Math.floor(price * 0.95);
  else if (price >= 300000 && price < 500000) return Math.floor(price * 0.9);
  else if (price >= 500000) return Math.floor(price * 0.8);
  else return price;
}
