public class leetcode_38_Count and Say_황소 {
    // 참고: https://leetcode.com/problems/count-and-say/discuss/254369/Clean-Short-Java-Solution
    public static void main(String[] args) {
        int n = 4; // 문제 조건은 1 이상 30 이하 자연수
        System.out.println(countAndSay(n));
    }

    public static String countAndSay(int n) {
        if (n == 1) return "1"; // 초기값

        StringBuilder answer = new StringBuilder();

        String next = countAndSay(n - 1) + "0"; // 임시로 0만 하나 붙여두고
        int len = next.length();
        for (int i = 0, c = 1; i < len - 1; i++, c++) { // 밑에서 i와 i + 1를 비교해야 하니까 범위는 0이상 len-2이하
            // c는 몇 개 있는지 세는 역할. 1부터 시작.
            if (next.charAt(i) != next.charAt(i + 1)) {
                answer.append(c).append(next.charAt(i));
                c = 0; // 한번 달라지면 0부터 초기화시킨 다음에 1씩 더하기
            }
        }

        return answer.toString();
    }
}