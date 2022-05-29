class Solution {
    public int solution(int left, int right) {
        int answer = 0;

        for (int i = left; i <= right; i++) {
            int count = division(i);
            if (count % 2 == 0) { //짝수
                answer += i;
            }
            else {
                answer -= i;
            }
        }
        return answer;
    }

    public int division (int num) {
        int i = 1;
        int count = 0;
        while (i <= num) {
            if (num % i == 0) {
                count++;
            }
            i++;
        }
        return count;
    }
}