import java.util.Arrays;

public class leetcode_976_Largest Perimeter Triangle_황소 {
    // perimeter: 둘레
    public static void main(String[] args) {
        int[] nums = {1, 2, 1};
        System.out.println(largestPerimeter(nums));
    }

    public static int largestPerimeter(int[] nums) {
        Arrays.sort(nums); // Arrays.sort(array, Collections.reverseOrder())는 Integer[]였다면 가능
        for (int i = nums.length - 1; i >= 2; i--) {
            if (nums[i] < nums[i - 1] + nums[i - 2]) { // 어차피 제일 커다란 것들끼리 비교하니 이 경우의 수만 고려하면 ok
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return 0;
    }
}