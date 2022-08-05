function solution(x) {
    var answer = true;
    var digits = String(x).split(''); // 숫자-> 문자열-> 문자 하나를 배열 한칸에 넣어주기
    var temp = 0;
    for(var i = 0; i < digits.length; i++)
        temp += Number(digits[i]);
    if (x % temp != 0)
        answer = false;
    return answer;
}