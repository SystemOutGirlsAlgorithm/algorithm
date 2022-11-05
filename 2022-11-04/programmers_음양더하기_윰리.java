class Solution {

    public int solution(int[] absolutes, boolean[] signs) {
        int answer = 0;

        for (int i = 0; i < absolutes.length; i++) {
            if (signs[i]) {
                answer += absolutes[i];
                continue;
            }
            answer -= absolutes[i];
        }

        System.out.println("answer = " + answer);
        return answer;
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution(new int[]{4, 7, 12}, new boolean[]{true, false, true}); //9
        s.solution(new int[]{1,2,3}, new boolean[]{false,false,true}); //0
    }
}