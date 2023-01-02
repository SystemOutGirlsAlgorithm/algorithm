/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
 var removeElement = function(nums, val) {
    for(let i=0; i<nums.length; i++) {
        if(nums[i] === val) {
            nums.splice(i, 1); //nums[i]가 val과 같으면 splice
            i--;
        }
    }
    return nums.length; //결과값 반환
};