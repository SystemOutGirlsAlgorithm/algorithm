/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  strs.sort(); // 알파벳순으로 정렬
  for (let i = 0; i < strs[0].length; i++) {
    // 한글자씩 비교하다가 다른거 나오면 거기까지 잘라서 return
    if (strs[0][i] !== strs[strs.length - 1][i]) return strs[0].substr(0, i);
  }
  return strs[0];
};
