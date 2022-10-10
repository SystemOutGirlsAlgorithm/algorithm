import java.util.ArrayList;
import java.util.List;

/*
 * Given an integer n,
 * return a string array answer(1 ~ indexed)
 *
 * if i is divisible by 3 and 5 -> answer[i] == FizzBuzz
 * divisible by only 3 -> Fizz
 * divisible by only 5 -> Buzz
 * none of the conditions match -> just i
 * */

public class leetcode_412_Fizz Buzz_황소 {
    public static void main(String[] args) {
        int n = 5; // 3 or 5 or 15
        System.out.println(fizzBuzz(n));
    }

    public static List<String> fizzBuzz(int n) {
        // 1st try
        /*List<String> answer = new ArrayList<>(); // ArrayList resize automatically, so sizing is not crucial
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                answer.add(i - 1, "FizzBuzz");
            } else if (i % 3 == 0) {
                answer.add(i - 1, "Fizz");
            } else if (i % 5 == 0) {
                answer.add(i - 1, "Buzz");
            } else {
                answer.add(i - 1, String.valueOf(i));
            }
        }*/
        // video solution #1(leetcode) - Time Complexity: O(n) Space Complexity: O(1)
        List<String> answer = new ArrayList<>(n);
        for (int i = 1; i <= n; i++) {
            boolean divisibleBy3 = i % 3 == 0;
            boolean divisibleBy5 = i % 5 == 0;

            if (divisibleBy3 && divisibleBy5) {
                answer.add("FizzBuzz");
            } else if (divisibleBy3) {
                answer.add("Fizz");
            } else if (divisibleBy5) {
                answer.add("Buzz");
            } else {
                answer.add(String.valueOf(i));
            }
        }
        // video solution #2(leetcode) - Time Complexity: O(n), Space Complexity: O(1)
        /*List<String> answer = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            boolean divisibleBy3 = i % 3 == 0;
            boolean divisibleBy5 = i % 5 == 0;
            String currStr = "";
            if (divisibleBy3) {
                currStr += "Fizz";
            }
            if (divisibleBy5) {
                currStr += "Buzz";
            }
            if (currStr.isEmpty()) {
                currStr += String.valueOf(i);
            }
            answer.add(currStr);
        }*/
        return answer;
    }
}