import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class Beakjoon_11279_LM {
  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < N; i++) {
      int num = Integer.parseInt(br.readLine());

      if (num == 0)
        sb.append(q.size() == 0 ? 0 : q.poll()).append('\n');
      else
        q.add(num);
    }

    System.out.println(sb.toString());
  }
}
