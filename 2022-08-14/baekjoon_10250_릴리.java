import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());    // testcase

        for(int i = 0; i < T; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            
            int H = Integer.parseInt(st.nextToken());
            int W = Integer.parseInt(st.nextToken());
            int N = Integer.parseInt(st.nextToken());

            int X = (N / H) + 1;  // 방 거리
            int Y = N % H;        // 방 층수

            if(Y == 0) {
              sb.append((H * 100) + (N / H)).append('\n');
            } else {
                sb.append((Y * 100) + X).append('\n');
            }
        }
        System.out.println(sb);
    }
}