public class leetcode_334_Increasing Triplet Subsequence_황소 {
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5};
        System.out.println(increasingTriplet(nums));
    }

    // index 복수형이 indices? - indexes이런 단어는 없나? - indexes도 맞는 표현이지만 특정 영역에서는 indices라고 표현
    // 순차적 증가 - 3개 뽑는 게 가능하면 true 아니면 false
    // 궁금한 점: i, j, k는 연속되어야 하나? -> 이런 조건은 안 보이니 연속되지 않아도 ok
    // for문을 안 쓰고 푸는 방법은... 없겠지? 있을까?
    public static boolean increasingTriplet(int[] nums) {
        // 4ms 84.3MB
        // beware of constraints: nums 길이가 3개 미만이 될 수도 있음
        /*if (nums.length < 3) return false;
        // minimum number seen so far & second number in the ascending triplet
        Integer min = nums[0]; // assign 1st number in the nums array
        Integer sec = null;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] <= min) {
                min = nums[i];
            } else {
                if (sec != null && nums[i] > sec) {
                    return true;
                }
                sec = nums[i];
            }
        }
        return false;*/

        // 2ms 93.3MB
        if (nums.length < 3) return false;
        int first = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;
        for (int num : nums) {
            if (num <= first) {
                first = num;
            } else if (num <= second) {
                second = num;
            } else {
                return true;
            }
        }
        return false;
    }
}

/*
 * 인덱스값의 증가에 따라 값이 오름차순으로 변하는 3개가 있는지 물어보는 문제
 * 그러므로 첫번째 값은 가장 작아야 하고(first, min)
 * 두 번째 값은 첫 번째보다는 크고 마지막 수보다는 작아야 함
 * 1째 풀이: 등호를 빼먹지 않게 주의할 것: if (nums[i] <= min)
 * */