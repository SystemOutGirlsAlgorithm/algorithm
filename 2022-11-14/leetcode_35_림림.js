/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
 var searchInsert = function(nums, target) {
    for (let i = 0; i < nums.length; i++) {
        // nums 배열에 target 있으면
        if(nums.includes(target)) {
            // nums 배열에서 target의 인덱스 번호 추출
            return nums.indexOf(target);
        // nums 배열에 target 없으면
        } else {
            nums.push(target); // nums 배열에 target push
            nums.sort((a,b) => a-b); // 오름차순
            // nums 배열에서 target의 인덱스 번호 추출
            return nums.indexOf(target);
        }
    }
};