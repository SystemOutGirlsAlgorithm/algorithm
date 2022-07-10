function solution(s) {
    s = s.split(" ");
    let answer = "";
    for (let i = 0; i < s.length; i++) {
        for (let j = 0; j < s[i].length; j++) {
            answer += j % 2 === 0 ? s[i][j].toUpperCase() : s[i][j].toLowerCase();
        }
        i === s.length - 1 ? (answer += "") : (answer += " ");
    }
    return answer;
}
