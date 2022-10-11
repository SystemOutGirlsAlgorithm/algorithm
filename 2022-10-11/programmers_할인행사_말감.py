function solution(want, number, discount) {
    let answer = 0;
    for (let i = 0; i+10 < discount.length+1; i++) {
        let wantNum = [];
        want.map((thing, index) => wantNum.push(discount.slice(i, i+10).filter((el) => el === thing).length));
        if (wantNum.filter((el, i) => number[i] === el).length === number.length) answer += 1;
    }
    return answer;
}