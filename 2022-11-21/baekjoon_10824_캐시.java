package baekjoon.string;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//네 수
public class baekjoon_10824_캐시 {
    public static void main(String[] args) throws IOException {
      //1. 문자열 입력 > 문자열 분리
      //2. A+B (더하기 X)
      //3. C+D
      //4. 2+3한거 출력하기
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        String ab = st.nextToken() + st.nextToken();
        String cd = st.nextToken() + st.nextToken();

        System.out.println(Long.parseLong(ab) + Long.parseLong(cd));
    }
}
