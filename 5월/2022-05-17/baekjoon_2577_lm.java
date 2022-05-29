import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Baekjoon_2577_LM {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);

    /**
     * 시간 복잡도가 높기에 추천하지 않는다.
     */
    int total = (sc.nextInt() * sc.nextInt() * sc.nextInt());
    String strTotal = Integer.toString(total);

    for (int i = 0; i < 10; i++) {
      int count = 0;
      for (int j = 0; j < strTotal.length(); j++) {
        // charAt() 사용시 -'0' or '-48' 필요하다
        // 안 할 시 아스키코에 대응하 문자 나옴
        if ((strTotal.charAt(j) - '0') == i) {
          count++;
        }
      }
      System.out.println(count);
    }
  }
}
