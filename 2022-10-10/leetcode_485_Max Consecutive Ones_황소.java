public class leetcode_485_Max Consecutive Ones_황소 {
    // return the maximum number of consecutive 1s in the array
    public static void main(String[] args) {
        int[] nums = {1, 1, 0, 1, 1, 1};
        System.out.println(findMaxConsecutiveOnes(nums));
    }
    public static int findMaxConsecutiveOnes(int[] nums) {
        int maxRecord = 0;
        int count = 0;

        /* for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                count += 1;
            }
            if (nums[i] != 1 || i == (nums.length - 1)) {
                if (count > maxRecord) {
                    maxRecord = count;
                }
                count = 0;
            }
        } */
        // 출처: https://leetcode.com/problems/max-consecutive-ones/discuss/96693/Java-4-lines-concise-solution-with-explanation
        /* for (int num : nums) {
            maxRecord = Math.max(maxRecord, count = (num == 0 ? 0 : count + 1));
        }
        return maxRecord; */
        for (int i = 0; i < nums.length; i++) { // enhanced for문을 사용했는데 runtime 증가? 출처: https://leetcode.com/problems/max-consecutive-ones/discuss/96715/Easy-Java-Solution
            if (nums[i] == 1) {
                count++;
                maxRecord = Math.max(count, maxRecord);
            }
            else count = 0;
        }
        return maxRecord;
    }
}