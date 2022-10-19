class Solution {

    public int[] solution(String s) {
         int sLen = s.length();
         int count0 = 0;//총 제거된 0의 수
         int changeCount = 0;//2진 변환 수
         int nextNum;
        while (s.length() > 1) {
            changeCount++;
            nextNum = remove0(s).length(); //1만 남은 s
            count0 += sLen - nextNum; //s의 길이 - 1만 남은 s == 제거된 0의 갯수
            s = Integer.toString(nextNum, 2); //1만 남은 s의 길이 2진 변환
            sLen = s.length();
        }

//        System.out.println("changeCount = " + changeCount);
//        System.out.println("count0 = " + count0);
        return new int[]{changeCount, count0};
    }

    public String remove0(String str) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '1') {
                sb.append("1");
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution("110010101001"); //3, 8
        s.solution("01110"); //3, 3
        s.solution("1111111"); //4, 1
    }
}