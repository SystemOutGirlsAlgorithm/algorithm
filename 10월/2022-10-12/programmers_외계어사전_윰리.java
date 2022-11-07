class Solution {

    public int solution(String[] spell, String[] dic) {
        int answer = 2;

        for (String word : dic) {
            int count = 0;
            for (String s : spell) {
                if (word.indexOf(s) >= 0) {
                    if (word.indexOf(s) != word.lastIndexOf(s)) {
                        continue;
                    }
                    count++;
                }
            }
            if (count == spell.length) {
                answer = 1;
                break;
            }
        }

        System.out.println(answer);
        return answer;
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution(new String[]{"z", "d", "x"}, new String[]{"def", "dww", "dzx", "loveaw"});
        s.solution(new String[]{"p", "o", "s"}, new String[]{"sod", "eocd", "qixm", "adio", "soo"});
    }
}