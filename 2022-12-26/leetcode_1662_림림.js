/**
 * @param {string[]} word1
 * @param {string[]} word2
 * @return {boolean}
 */
 var arrayStringsAreEqual = function(word1, word2) {
    let newword1 = word1.join(''); //word1 배열에 있는 값 합치기
    let newword2 = word2.join(''); //word2 배열에 있는 값 합치기
    // 두 값이 같으면 true 그외에는 false
    if(newword1 === newword2) {
        return true;
    } else {
        return false;
    }
};