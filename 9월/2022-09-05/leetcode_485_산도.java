class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int x = 0;
        int result = 0;
        for (int num : nums){
            x = num == 0 ? 0 : x+1;
            result = result < x ? x : result;
            }
        return result;
    }
}