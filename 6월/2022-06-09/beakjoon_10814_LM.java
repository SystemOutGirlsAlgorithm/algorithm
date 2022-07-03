import java.util.*;

public class Baekjoon_10814_LM {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    String arr[][] = new String[n][3];
    sc.nextLine();

    for (int i = 0; i < n; i++) {
      String s = sc.nextLine();
      String temp[] = s.split(" ");
      arr[i][0] = temp[0];
      arr[i][1] = temp[1];
      arr[i][2] = Integer.toString(i);
    }

    Arrays.sort(arr, (a, b) -> {
      if (a[0] == b[0]) {
        return a[2].compareTo(b[2]);
      } else {
        return Integer.parseInt(a[0]) - Integer.parseInt(b[0]);
      }
    });

    for (int i = 0; i < n; i++) {
      System.out.println(arr[i][0] + " " + arr[i][1]);
    }
  }
}
