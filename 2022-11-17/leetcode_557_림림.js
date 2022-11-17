/**
 * @param {string} s
 * @return {string}
 */
 var reverseWords = function(s) {
    // 뒤집고 순서 바꾸기
    let sp = s.split('').reverse().join(''); // 문자열을 하나씩 구분해서 배열로 만들고 뒤집은 다음에 join써서 다시 문자열로
    let sp2 = sp.split(' ').reverse().join(' '); // 한번 더 문자열을 빈칸 기준으로 구분해서 배열로 만들고 뒤집은 다음에 빈칸 기준으로 join써서 다시 문자열로
    return sp2; // 결과값 반환
};