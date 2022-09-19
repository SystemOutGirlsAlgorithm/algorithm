package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class n13172 {
    static long mul(long b, long x, long y) {
         long ans = 1;
         while (x > 0) {
             if (x%2 != 0) {
                 ans *= b;
                 ans %= y;
             }
             b *= b;
             b %= y;
             x/=2;
         }
         return ans;
    }

    static long M, N, S, P = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Long.parseLong(st.nextToken());
        long ans = 0;
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            N = Long.parseLong(st.nextToken());
            S = Long.parseLong(st.nextToken());

            long N_ = mul(N, P-2, P);
            ans += (S%P)*N_;
            ans %= P;
        }

        System.out.println(ans);
    }
}
