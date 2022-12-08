class Solution {

    public int solution(int n, int a, int b) {
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        int round = 1;
        while (!(b - a == 1 && b % 2 == 0)) {
            a = a % 2 == 0? a : a + 1;
            b = b % 2 == 0? b : b + 1;
            a = a / 2;
            b = b / 2;
            round++;
        }

        return round;
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution(8, 4, 7); //3
    }
}