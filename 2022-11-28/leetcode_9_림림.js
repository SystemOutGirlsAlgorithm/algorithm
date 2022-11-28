/**
 * @param {number} x
 * @return {boolean}
 */
 var isPalindrome = function(x) {
    let a = String(x); // 숫자 -> 문자열로
    let b = a.split('').reverse().join(''); // 문자열 -> 배열 -> 문자열
    if (a === b) { // 두 개 값이 같으면
        return true; // true 반환
    } else { // 같지 않으면
        return false; // false 반환
    }
};