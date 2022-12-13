/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
 var containsNearbyDuplicate = function(nums, k) {
    const map = new Map(); //맵을 만듦(맵은 키가 있는 데이터를 저장하는 부분에서 객체와 비슷)
    for(let i=0; i < nums.length; i++){
        if(map.has(nums[i]) && i - map.get(nums[i]) <= k) { //맵이 nums[i]를 가지고 있고, i - map.get(nums[i])<=k이면
            return true; //true 반환
        }
        map.set(nums[i], i); //nums[i] key를 이용해 i value 저장
    }
    return false; //그외엔 false 반환
};