/* 실패한 풀이
function solution(n, stations, w) {
  // 전기가 전달되지 않는 곳의 시작점과 끝점을 left에 담음
  let left = [];
  let count = 0;

  for(let i = 0; i < stations.length; i++){
      if(stations[i] - w > 0) left.push(stations[i] - w)
      if(stations[i] + w < n+1) left.push(stations[i] + w)
  }
  // 전달되지 않는 범위의 길이가 2*w+1를 넘지 않으면 1대로 커버가능하고
  // 넘어가면 범위의 길이를 2*w+1로 나눈 값을 올림하면 된다
  for(let j = 0; j < left.length; j++){
      if(left[j] <= 2*w+1) count += 1;
      else count += Math.ceil(left[j]/(2*w+1))
  }
  // 그런데 생각한 것과는 달리 결과가 계속 틀림
  return count;
}
*/

// 다른 사람 풀이
function solution(n, stations, w) {
  let answer = 0;
  const coverage = w * 2 + 1;

  // endPoint는 마지막 기지국 설치 이후로 전파가 닿지 않는 첫 아파트 위치
  const endPoint =
    n -
    stations.reduce((prev, cur) => {
      // 첫 prev = 0이기 때문에 첫 아파트 - 현재 기지국 전파 범위 이전 아파트까지
      // 해당하는 구간의 총 아파트 개수 파악이 가능
      // 이후 prev는 기지국 간에 전파가 닿지 않는 구간 파악이 가능
      const appartments = cur - w - 1 - prev; // 아파트 개수
      // appartments -1을 coverage로 나눈 몫 +1가 최종적으로 설치되는 기지국 개수
      // 만약 아파트가 해당 구간에 존재하지 않는다면 설치 x
      answer +=
        appartments > 0 ? Math.floor((appartments - 1) / coverage) + 1 : 0;
      return cur + w;
    }, 0);

  // endPoint > 0이면 즉 마지막 기지국의 전파가 닿지 않는 아파트가 존재한다면
  // 현재 기지국이 커버 가능한 위치는 제외해야 하기 때문에 endPoint-1을 coverage로 나눈 값을 내림하고 +1
  if (endPoint > 0) answer += Math.floor((endPoint - 1) / coverage) + 1;

  return answer;
}
