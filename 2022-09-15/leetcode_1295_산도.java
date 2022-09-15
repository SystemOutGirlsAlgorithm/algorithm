class Solution {
    public int findNumbers(int[] nums) {
        int result = 0;
        for(int num : nums){
            result = countDigit(Long.valueOf(num)) % 2 == 0 ? result+1 : result;
        }
        
        return result;
    } 
    
    static int countDigit(long n)
    {
        if (n/10 == 0)
            return 1;
        return 1 + countDigit(n / 10);
    }
}