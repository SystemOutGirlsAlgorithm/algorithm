class Solution {
    public int[] sortedSquares(int[] nums) {
        int j = nums.length;
        int[] result = new int[j];
        int i = 0;
        int k = 0;
        j--;
        k = j;
        
        while (k >= 0) {
            if (Math.abs (nums[i]) > Math.abs (nums[j])) {
                result[k--] = nums[i] * nums[i++];
            }
            else {
                result[k--] = nums[j] * nums[j--];
            }
        }
        
        return result;
    }
}