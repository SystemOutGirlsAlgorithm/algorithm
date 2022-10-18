class Solution {

    public int solution(int n) {

        int answer = 0;
        for (int i = 2; i < n; i++) {
            if (n % i == 1) {
                answer = i;
                break;
            }
        }
//        System.out.println(answer);
        return answer;
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution(10);
        s.solution(12);
    }
}