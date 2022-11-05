class Solution {

    public int solution(int left, int right) {
        int answer = 0;

        for (int i = left; i <= right; i++) {
            if (countMeasure(i) % 2 == 0) {
                answer += i;
                continue;
            }
            answer -= i;
        }

        System.out.println("answer = " + answer);
        return answer;
    }

    public int countMeasure(int num) {

        int count = 0;
        boolean isSqrt = false;
        for (int i = 1; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                count++;
                if (i == Math.sqrt(num)) {
                    isSqrt = true;
                }
            }
        }
        count += isSqrt ? count - 1 : count;

        return count;
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution(13, 17); //43
        s.solution(24, 27); //52
    }
}