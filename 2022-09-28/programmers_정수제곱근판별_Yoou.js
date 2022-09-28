function solution(n) {
    var answer = 0;
    answer = Math.sqrt(n);
    if (answer % 1 !== 0)
        answer = -1;
    else
        answer = (answer + 1) * (answer + 1);
    return answer;
}