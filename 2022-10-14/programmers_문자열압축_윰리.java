class Solution {

    public int solution(String s) {

        int answer = s.length();
        for (int i = 1; i <= s.length() / 2; i++) {
            answer = Math.min(compressFromFirst(s, i), answer);
        }

//        System.out.println(answer);
        return answer;
    }

    public int compressFromFirst(String s, int len) {
        String standard = s.substring(0, len);
        String result = "";
        int count = 1;
        for (int i = len; i <= s.length(); i += len) {
            String substring = s.substring(i, i + len > s.length() ? s.length() : i + len);
            if (standard.equals(substring)) {
                count++;
                continue;
            }
            if (count > 1) {
                result += String.valueOf(count);
                count = 1;
            }
            result += standard;
            standard = substring;
        }
        result += standard;

//        System.out.println("result = " + result);
        return result.length();
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution("aabbaccc");
        s.solution("ababcdcdababcdcd");
        s.solution("abcabcdede");
        s.solution("abcabcabcabcdededededede");
        s.solution("xababcdcdababcdcd");
        s.solution("aaaaaaaaaab"); //4
    }
}