/**
 * @param {string[]} strs
 * @return {string}
 */
 var longestCommonPrefix = function(strs) {
    // 이중 for문 사용
    for(let i=0; i < strs[0].length; i++) {
        for(let j of strs) {
            if(j[i] !== strs[0][i]) {
                return j.slice(0, i);
            }
        }
    }
};