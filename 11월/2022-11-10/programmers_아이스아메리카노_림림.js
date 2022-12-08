function solution(money) {
    let answer = [];
    let maxCoffee = parseInt(money / 5500); // 최대 잔수
    let change = money % 5500; // 잔돈
    answer.push(maxCoffee, change); // 배열에 값 넣어주기
    return answer;
}