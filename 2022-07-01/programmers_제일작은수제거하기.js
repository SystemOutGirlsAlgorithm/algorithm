function solution(arr) {
    const answer = [];
    if (arr.length === 1) {
        answer.push(-1);
    } else {
        const min = Math.min(...arr);
        arr.forEach((v) => {
            if (v !== min) {
                answer.push(v);
            }
        });
    }
    return answer;
}
