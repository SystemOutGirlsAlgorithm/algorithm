import java.io.*;
import java.util.StringTokenizer;

public class baekjoon_10952_jxx {
    public static void main(String[] args) throws IOException {
        // A+B-5
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st; // 입력받을 A와 B를 저장하기 위해 StringTokenizer 선언

        while (true){
            st = new StringTokenizer(br.readLine()); // 입력받을 A와 B를 입력
            int A = Integer.parseInt(st.nextToken()); // A 저장
            int B = Integer.parseInt(st.nextToken()); // B 저장

            if (A == 0 && B == 0){
                break;
            }
            bw.write(A + B + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
