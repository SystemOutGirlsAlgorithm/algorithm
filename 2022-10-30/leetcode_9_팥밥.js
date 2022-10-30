/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function (x) {
  let reverseX = +x.toString().split("").reverse().join("");

  return reverseX == x ? true : false;
};
