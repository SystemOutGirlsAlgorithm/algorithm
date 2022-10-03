import java.util.Arrays;

public class leetcode_1480_황소 { // RunningSumOf1DArray_1480

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4};
        System.out.println(Arrays.toString(runningSum(nums)));
    }

    public static int[] runningSum(int[] nums) {
        int[] answer = new int[nums.length];
        int cal = 0;
        for (int i = 0; i < nums.length; i++) {
            cal += nums[i];
            answer[i] = cal;
        }
        return answer;
    }
}