function solution(n) {
    let answer = String(n).split("");
    answer = answer.sort().reverse().join("");
    answer = Number(answer);
    return answer;
}
