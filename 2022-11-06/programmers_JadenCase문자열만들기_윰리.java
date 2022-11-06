class Solution {

    public String solution(String s) {

        s = s.toLowerCase();

        int gap = 'a' - 'A';

        StringBuilder sb = new StringBuilder();
        //다음 문자 단어 시작 여부
        boolean isStart = true;
        char charI;
        for (int i = 0; i < s.length(); i++) {
            charI = s.charAt(i);

            //단어 시작인 경우
            if (isStart) {
                isStart = false;

                //소문자인 경우
                if (charI >= 'a') {
                    charI -= gap;
                }
            }

            sb.append(charI);

            //공백인 경우
            if (charI == ' ') {
                isStart = true;
            }
        }
        
        String answer = sb.toString();
//        System.out.println("answer = " + answer);
        return answer;
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution("3people unFollowed me");
        s.solution("for the last week");
    }
}