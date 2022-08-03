function solution(phone_number) {
    var answer = '';
    answer = '*'.repeat(phone_number.length - 4) + phone_number.substring(phone_number.length - 4);
    return answer;
}