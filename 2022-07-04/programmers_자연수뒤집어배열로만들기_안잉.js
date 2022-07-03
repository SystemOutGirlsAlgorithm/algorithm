const solution = (n) => {
    let answer = [];
    answer = String(n)
        .split("")
        .map((v) => Number(v))
        .reverse();
    return answer;
};
