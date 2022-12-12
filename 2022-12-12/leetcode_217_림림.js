/**
 * @param {number[]} nums
 * @return {boolean}
 */
 var containsDuplicate = function(nums) {
    const set = new Set(nums); //Set은 중복값을 제거해줌
    if(set.size !== nums.length) { //Set의 길이는 .size
        return true;
    } else {
        return false;
    }
};