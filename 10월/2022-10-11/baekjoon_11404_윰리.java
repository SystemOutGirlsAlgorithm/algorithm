import java.io.*;
import java.util.*;

public class Main {

    public static final int MAXVALUE = (int) 1e9;

    public void solution(int n, int m, int[][] graph) {
        int[][] dp = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = graph[i].clone();
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                if (i == k) {
                    continue;
                }
                for (int j = 1; j <= n; j++) {
                    if (i == j || k == j) {
                        continue;
                    }
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][j] == MAXVALUE || i == j) {
                    dp[i][j] = 0;
                }
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws IOException {
        Main main = new Main();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        int[][] graph = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == j) {
                    continue;
                }
                graph[i][j] = MAXVALUE;
            }
        }
        for (int i = 0; i < m; i++) {
            int[] path = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(Integer::parseInt)
                    .toArray();
            graph[path[0]][path[1]] = Math.min(path[2], graph[path[0]][path[1]]);
        }

        main.solution(n, m, graph);
    }
}