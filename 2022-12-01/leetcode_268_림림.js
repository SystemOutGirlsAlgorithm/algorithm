/**
 * @param {number[]} nums
 * @return {number}
 */
 var missingNumber = function(nums) {
    nums.sort((a,b) => a-b); // 오름차순
    for(let i = 0; i < nums.length; i++) {
        if(i !== nums[i]) {
            return i;
        }
    }
    return nums.length;
};