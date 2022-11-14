/**
 * Definition for isBadVersion()
 * 
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        let left = 1;
        let right = n;
        while(left < right) {
            const mid = Math.floor((right + 1) / 2);
            // 중앙값이 BadVersion이 아니면 mid에 1을 더한 값
            if (!isBadVersion(mid)) {
                return left = mid + 1;
            // 그외 중앙값이 BadVersion이면 mid값 
            } else {
                return right = mid;
            }
        }
        return left;
    };
};