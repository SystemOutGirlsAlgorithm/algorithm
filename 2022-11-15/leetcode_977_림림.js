/**
 * @param {number[]} nums
 * @return {number[]}
 */
 var sortedSquares = function(nums) {
    let newNum = []
    for (let i = 0; i < nums.length; i++) {
        let square = (nums[i])*(nums[i])
        newNum.push(square);
    }
    newNum.sort((a,b) => a-b); // for문 다돌리고, 오름차순 정렬 (for문 안에서 정렬하면 시간 너무 오래걸림)
    return newNum;
};