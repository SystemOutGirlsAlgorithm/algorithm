function solution(n) {
    var answer = 0;
    let str = String(n);
    arr = str.split('');
    arr.sort(function(a, b){return (b - a);});
    str = arr.join('');
    answer = Number(str);
    return answer;
}ㄴ