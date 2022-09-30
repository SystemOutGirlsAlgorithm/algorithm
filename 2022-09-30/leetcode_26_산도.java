class Solution {
    public int removeDuplicates(int[] nums) {
        int i = nums.length > 0 ? 1 : 0;
        
        for (int n : nums)
            if (n > nums[i-1])
                nums[i++] = n;
        
        return i;
    }
}