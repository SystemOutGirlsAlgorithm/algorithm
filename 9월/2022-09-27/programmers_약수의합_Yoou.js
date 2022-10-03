function solution(n) {
    var answer = 0;
    for(let i = 1; i <= n; i++)
    {
        if (n % i === 0)
            answer += i;
    }
    return answer;
}