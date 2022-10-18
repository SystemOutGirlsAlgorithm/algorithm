class Solution {

    public int solution(int n) {

        String str3 = Integer.toString(n, 3);

        StringBuilder sb = new StringBuilder();
        for (int i = str3.length() - 1; i >= 0; i--) {
            sb.append(str3.charAt(i));
        }

        int answer = Integer.parseInt(sb.toString(), 3);
//        System.out.println(answer);
        return answer;
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution(45);
        s.solution(125);
    }
}