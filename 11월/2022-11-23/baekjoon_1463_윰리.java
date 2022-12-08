import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {

    public void solution(int n) {
        if (n == 1) {
            System.out.println(0);
            return;
        }
        if (n < 4) {
            System.out.println(1);
            return;
        }
        int[] dp = new int[n + 1];
        dp[2] = 1;
        dp[3] = 1;

        for (int i = 4; i <= n; i++) {
            if (i % 3 == 0) {
                dp[i] = dp[i / 3] + 1;
            }
            if (i % 2 == 0) {
                if (dp[i] == 0) {
                    dp[i] = dp[i / 2] + 1;
                } else {
                    dp[i] = Math.min(dp[i], dp[i / 2] + 1);
                }
            }
            dp[i] = dp[i] == 0 ? dp[i - 1] + 1 : Math.min(dp[i], dp[i - 1] + 1);
        }
//        System.out.println(Arrays.toString(dp));
        System.out.println(dp[n]);
    }

    public static void main(String[] args) throws IOException {
        Main main = new Main();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        main.solution(n);
    }
}