public class leetcode_1328_Break a Palindrome_황소 {
    public static void main(String[] args) {
        String palindrome = "abccba";
        System.out.println(breakPalindrome(palindrome));
    }

    // 출처: https://jaime-note.tistory.com/114
    public static String breakPalindrome(String palindrome) {
        int len = palindrome.length();
        if (len <= 1) return "";
        char[] letters = palindrome.toCharArray();
        for (int i = 0; i < (len / 2); i++) {
            if (letters[i] != 'a') {
                letters[i] = 'a';
                return String.valueOf(letters); // toString()은 객체값 나옴
            }
        }
        letters[len - 1] = 'b';
        return String.valueOf(letters);
    }
}