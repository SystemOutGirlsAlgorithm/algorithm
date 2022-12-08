// 순열에 대해 알고 있어야 풀 수 있는 문제
// 풀다가 못풀어 답안 참고, But 문제풀이도 완전히 이해못함, *다시 이해 필요
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
 var checkInclusion = function(s1, s2) {
    if(s1.length > s2.length) return false;
    
    const stringCount = Array(26).fill(0); // 알파벳 개수가 26개이므로
    
    // 배열에 0 check
    const checkZero = targetStringCount => {
        for (let i = 0; i < 26; i++) {
            if (targetStringCount[i] !== 0) return false;
        }
        return true;
    }

    for (let i = 0; i < s1.length; i++) {
        stringCount[s1.charCodeAt(i) - 'a'.charCodeAt(0)]++; // string.charCodeAt(index)는 index에 해당하는 문자의 unicode 값을 리턴
    }

    for (let j = 0; j < s2.length; j++) {
        stringCount[s2.charCodeAt(j) - 'a'.charCodeAt(0)]--;
        if (j - s1.length >= 0) stringCount[s2.charCodeAt(j - s1.length) - 'a'.charCodeAt(0)]++;
        if (checkZero(stringCount)) return true;
    }

    return false;
};