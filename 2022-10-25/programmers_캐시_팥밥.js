// 못 풀어서 다른 사람 풀이 참고
function solution(cacheSize, cities) {
  let answer = 0;
  let cache = [];
  //캐시 크기가 0인 경우는 따로 처리
  if (cacheSize === 0) return cities.length * 5;

  // 캐시 크기가 1이상인 경우
  while (cities.length) {
    // 제일 왼쪽 요소를 city에 저장
    const city = cities.shift().toLowerCase();
    // city가 cache 배열에 들어가 있으면
    // cache hit이니까 +1
    if (cache.includes(city)) {
      cache.splice(cache.indexOf(city), 1);
      cache.push(city);
      answer += 1;
    } else {
      // city가 cache배열에 없으면 cache miss니까 +5
      if (cache.length === cacheSize) {
        cache.shift();
      }
      cache.push(city);
      answer += 5;
    }
  }
  return answer;
}
