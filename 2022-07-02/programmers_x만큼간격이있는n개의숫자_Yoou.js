function solution(x, n) {
    var answer = [];
    for(let cnt = 0; cnt < n; cnt++)
        answer.push(x + x * cnt);
    return answer;
}