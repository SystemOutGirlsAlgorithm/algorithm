import java.util.HashSet;
import java.util.Set;

class Solution {

    public int[] solution(int n, String[] words) {
        int[] result = new int[2];

        Set<String> answer = new HashSet<>();

        int index = 0;
        for (int i = 0; i < words.length; i++) {
            if (words[i].length() == 1) {
                index = i;
                break;
            }
            if (!answer.add(words[i])) {
                index = i;
                break;
            }
            if (i > 0 && words[i].charAt(0) != words[i - 1].charAt(words[i - 1].length() - 1)) {
                index = i;
                break;
            }
        }
        index++;

        if (words.length != answer.size()) {
            if (index % n == 0) {
                result[0] = n;
                result[1] = index / n;
            } else {
                result[0] = index % n;
                result[1] = index / n + 1;
            }
        }

//        System.out.println(Arrays.toString(result));
        return result;
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution(3, new String[]{"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});
        s.solution(5, new String[]{"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"});
        s.solution(2, new String[]{"hello", "one", "even", "never", "now", "world", "draw"});
    }
}