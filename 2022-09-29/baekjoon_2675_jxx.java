import java.io.*;
import java.util.StringTokenizer;

public class baekjoon_2675_jxx {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st; // 입력받을 A와 B를 저장하기 위해 StringTokenizer 선언
        int T = Integer.parseInt(br.readLine());
        String S;
        int R;

        for (int i = 0; i < T; i++){ // 테스트케이스 반복
            String str = br.readLine(); // 입력받은 문자열
            st = new StringTokenizer(str);
            R = Integer.parseInt(st.nextToken()); // 반복 횟수
            S = st.nextToken(); // 반복할 문자열

            for (int j = 0; j < S.length(); j++){ // 문자열 반복
                String alpha = String.valueOf(S.charAt(j));
                for (int n = 0; n < R; n++){
                    System.out.print(alpha);
                }
            }
            System.out.println();
        }
    }
}
