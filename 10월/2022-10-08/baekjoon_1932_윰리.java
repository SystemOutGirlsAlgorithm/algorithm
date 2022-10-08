import java.io.*;
import java.util.*;

public class Main {

    public void solution(int n, int[][] graph) {
        int[][] dp = new int[n][n];
        for (int i = 0; i < graph.length; i++) {
            dp[i] = graph[i].clone();
        }

        dp[0][0] = graph[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + graph[i][j];
                    continue;
                }
                if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + graph[i][j];
                    continue;
                }
                dp[i][j] = Math.max(dp[i - 1][j - 1], dp[i - 1][j]) + graph[i][j];
            }
        }

//        for (int[] ints : dp) {
//            System.out.println(Arrays.toString(ints));
//        }

        int max = 0;
        for (int i = 0; i < n; i++) {
            max = Math.max(dp[n - 1][i], max);
        }
        System.out.println(max);
    }

    public static void main(String[] args) throws IOException {
        Main main = new Main();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[][] graph = new int[n][n];
        for (int i = 0; i < n; i++) {
            graph[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        main.solution(n, graph);
    }
}