/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
 var moveZeroes = function(nums) {
    for (let i = nums.length; i--;) {
        if (nums[i] === 0) {
            nums.splice(i,1); // arr.splice(start, deletecount)
            nums.push(0);
        }
    }
};