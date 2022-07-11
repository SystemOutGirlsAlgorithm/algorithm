import java.util.*;
class Solution {
  public int solution(String s) {
    s = s.replace("zero", "0").replace("one", "1").replace("two", "2").replace("three", "3").replace("four", "4").replace("five", "5").replace("six", "6").replace("seven", "7").replace("eight", "8").replace("nine", "9");
    int answer = 0;
    answer = Integer.parseInt(s);


    return answer;
  }
}