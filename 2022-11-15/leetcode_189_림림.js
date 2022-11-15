// 첫번째 방법 (time limit 초과 나옴)
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
 var rotate = function(nums, k) {
    for(let i = 0; i < k; i++) {
        nums.unshift(nums.pop());
    }
    return nums;
};

// 두번째 방법
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
 var rotate = function(nums, k) {
    k = k % nums.length;
    if (k === 0) {
        return nums;
    } else; {
        nums.splice(0, 0, ...nums.splice(nums.length - k, k)); // array.splice(start, deleteCount, items)
        return nums;
    }
};