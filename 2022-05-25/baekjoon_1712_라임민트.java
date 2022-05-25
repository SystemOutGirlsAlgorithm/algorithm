import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Beakjoon_1712_LM {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer stk = new StringTokenizer(br.readLine());

    int a = Integer.parseInt(stk.nextToken());
    int b = Integer.parseInt(stk.nextToken());
    int c = Integer.parseInt(stk.nextToken());

    if (c <= b) {
      System.out.println("-1");
    } else {
      System.out.println((a / (c - b)) + 1);
    }
  }
}