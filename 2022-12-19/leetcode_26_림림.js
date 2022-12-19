/**
 * @param {number[]} nums
 * @return {number}
 */
 var removeDuplicates = function(nums) {
    for (i = 0; i < nums.length; i++) {
        if (nums[i] === nums[i+1]) {
            nums.splice(i, 1);
            i--;
        }
    }
}