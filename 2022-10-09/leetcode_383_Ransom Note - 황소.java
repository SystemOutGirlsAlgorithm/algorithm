import java.util.HashMap;

public class leetcode_383_Ransom Note - 황소 {
    /*
     * magazine의 글자로 ransomeNote를 조합할 수 있으면 true, 아니면 false
     * magazine에 있는 글자는 1번씩만 사용 가능
     * ramsomNote, magazine 글자 개수는 10^5 이하고 자연수로 구성, 글자 종류는 영소문자
     * */
    public static void main(String[] args) {
        String ransomNote = "a";
        String magazine = "b";
        System.out.println(canConstruct(ransomNote, magazine));
    }
    public static boolean canConstruct(String ransomNote, String magazine) {
        // time complexity: O(m), space complexity: O(1) - 알파벳 수, 상수
        // HashMap 말고도 int[] 로도 가능할 듯(원리는 동일) (참고 사이트: https://ifuwanna.tistory.com/363)
        HashMap<Character, Integer> magazineLetters = new HashMap<>();
        for (int i = 0; i < magazine.length(); i++) {
            char m = magazine.charAt(i);
            int count = magazineLetters.getOrDefault(m, 0);
            magazineLetters.put(m, count + 1);
        } // 해시맵 기법: 해시맵에 magazine letters를 다 넣은 다음에 ransomNote와 비교할 때는 하나씩 빼내기
        for (int j = 0; j < ransomNote.length(); j++) {
            char r = ransomNote.charAt(j);
            int count = magazineLetters.getOrDefault(r, 0);
            if (count == 0) {
                return false;
            }
            magazineLetters.put(r, count - 1);
        }
        return true;
    }
}