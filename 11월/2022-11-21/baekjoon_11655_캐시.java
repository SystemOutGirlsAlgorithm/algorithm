package baekjoon.string;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//ROT13
public class baekjoon_11655_캐시 {
    public static void main(String[] args) throws IOException {
        //1. 문자열 s 입력
        //2. s를 한개씩
        //   - 대문자(65~90), 소문자(97~122) 13차이
        //   - 공백, 숫자는 그대로 출력
        //3. 빌더로 출력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String s = br.readLine();

        for (int i = 0; i < s.length(); i++) {
            int ch = s.charAt(i);
            System.out.println(ch);
            if (97 <= ch && ch <= 122) {
                ch += 13;
                if (ch > 122) ch -= 26;

            } else if (65 <= ch && ch <= 90) {
                ch += 13;
                if (ch > 90) ch -= 26;
            }
            sb.append((char) ch);
        }
        System.out.print(sb);
    }
}
