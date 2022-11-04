import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
// 손익분기점
public class baekjoon_1712_jxx {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken()); // 고정비용
        int B = Integer.parseInt(st.nextToken()); // 가변비용
        int C = Integer.parseInt(st.nextToken()); // 상품비용

        if (C > B){
            System.out.println(A / (C - B) + 1);
        } else {
            System.out.println("-1");
        }
        br.close();
    }
}