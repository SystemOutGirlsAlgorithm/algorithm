import java.io.*;
import java.util.StringTokenizer;

public class baekjoon_10951_jxx {
    public static void main(String[] args) throws IOException {
        // A+B-4
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st; // 입력받을 A와 B를 저장하기 위해 StringTokenizer 선언
        String str; // 왜?

        while ((str = br.readLine()) != null){
            st = new StringTokenizer(str); // 입력받을 A와 B를 입력
            int A = Integer.parseInt(st.nextToken()); // A 저장
            int B = Integer.parseInt(st.nextToken()); // B 저장
            bw.write(A + B + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}