import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class baekjoon_1978_jxx {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();	// 수의 개수 N
        StringTokenizer st = new StringTokenizer(br.readLine()); // 소수인지 판별할 N개의 수
        int cnt = 0; // 소수의 개수

        while(st.hasMoreTokens()) {

            boolean isPrime = true; // 소수는 true, 아닌 경우 false
            
            int num = Integer.parseInt(st.nextToken());

            if(num == 1) {
                continue;
            }
            for(int i = 2; i <= Math.sqrt(num); i++) {
                if(num % i == 0) { // 소수가 아닌 경우 false
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
