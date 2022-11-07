public class leetcode_1832_Check_if the Sentence is Pangram_황소 {
    public static void main(String[] args) {
        String sentence = "thequickbrownfoxjumpsoverthelazydog";
        System.out.println(checkIfPangram(sentence));
    }
    // 출처: https://leetcode.com/problems/check-if-the-sentence-is-pangram/discuss/1201598/Simple-java-0ms
    // 다른 방법으로는 Set<Character> set = new HashSet<>();, sentence.charAt(i) 등을 이용하는 것도
    public static boolean checkIfPangram(String sentence) {
        if (sentence.length() < 26) return false;
        for (char i = 'a'; i <= 'z'; i++) { // int뿐만이 아니라 char도 증가 가능
            if (sentence.indexOf(i) == -1) return false;
        }
        return true;
    }
}