class Solution {

    public int solution(int[] numbers) {

        boolean[] nums = new boolean[10];
        for (int number : numbers) {
            nums[number] = true;
        }

        int answer = 0;
        for (int i = 0; i < 10; i++) {
            if (!nums[i]) {
                answer += i;
            }
        }

        System.out.println("answer = " + answer);
        return answer;
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution(new int[]{1,2,3,4,6,7,8,0});
        s.solution(new int[]{5,8,4,0,6,7,9});
    }
}