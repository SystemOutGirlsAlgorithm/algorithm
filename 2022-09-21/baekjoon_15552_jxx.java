import java.io.*;
import java.util.StringTokenizer;

public class Baekjoon_15552 {
    public static void main(String[] args) throws IOException {
        // 빠른 A+B
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine()); // 테스트케이스의 개수 T를 입력

        StringTokenizer st; // 입력받을 A와 B를 저장하기 위해 StringTokenizer 선언

        for(int i = 0; i < T; i++){
            st = new StringTokenizer(br.readLine()); // 입력받을 A와 B를 입력
            int A = Integer.parseInt(st.nextToken()); // A 저장
            int B = Integer.parseInt(st.nextToken()); // B 저장
            bw.write(A + B + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
