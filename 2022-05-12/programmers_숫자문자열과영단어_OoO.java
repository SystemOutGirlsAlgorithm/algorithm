class Solution {
    public int solution(String s) {

        String[] num = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        String[] word = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        for (int i = 0; i < 10; i++) {
            s = s.replace(word[i], num[i]);
        }
        return Integer.parseInt(s);

        /*for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c >= 'a' && c <= 'z') {
                check += String.valueOf(c);
                change(check);
            }
            else {
                change(check);
                last += String.valueOf(c);
            }
        }
        answer = Integer.valueOf(last);
        return answer;
    }

    public static void change(String s) {
        if (s.equals("one")) {
            last += "1";
            check = "";
        }
        else if (s.equals("two")) {
            last += "2";
            check = "";
        }
        else if (s.equals("three")) {
            last += "3";
            check = "";
        }
        else if (s.equals("four")) {
            last += "4";
            check = "";
        }
        else if (s.equals("five")) {
            last += "5";
            check = "";
        }
        else if (s.equals("six")) {
            last += "6";
            check = "";
        }
        else if (s.equals("seven")) {
            last += "7";
            check = "";
        }
        else if (s.equals("eight")) {
            last += "8";
            check = "";
        }
        else if (s.equals("nine")) {
            last += "9";
            check = "";
        }*/
    }
}