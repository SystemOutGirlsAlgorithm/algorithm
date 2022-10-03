package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class n2096 {
    public static void main(String[] args) throws IOException {
        // INPUT
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int board[][] = new int[N][3];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // SOLUTION
        int dp[][][] = new int[N+1][5][2]; // 0: MIN, 1: MAX
        for (int i = 1; i <= N; i++) {
            dp[i][0][0] = 987654321;
            dp[i][4][0] = 987654321;
            for (int j = 1; j <= 3; j++) {
                dp[i][j][0] = board[i-1][j-1] + Math.min(dp[i-1][j-1][0], Math.min(dp[i-1][j][0], dp[i-1][j+1][0]));
                dp[i][j][1] = board[i-1][j-1] + Math.max(dp[i-1][j-1][1], Math.max(dp[i-1][j][1], dp[i-1][j+1][1]));
            }
        }

        System.out.printf("%d %d", Math.max(dp[N][1][1], Math.max(dp[N][2][1], dp[N][3][1])), Math.min(dp[N][1][0], Math.min(dp[N][2][0], dp[N][3][0])));

    }
}
