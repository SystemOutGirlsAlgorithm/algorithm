package baekjoon.string;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
//문자열 분석
public class baekjoon_10820_캐시 {
    public static void main(String[] args) throws IOException {
        //1. 문자열 입력
        //2. eof.
        //3. 배열의 크기 4 생성
        //4. 소문자, 대문자, 숫자, 공백 구별
        //5. 빌더로 출력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str;
        while ((str = br.readLine()) != null && !str.isEmpty()) {
            int[] count = new int[4];
            for (char c : str.toCharArray()) {
                if (c >= 'a' && c <= 'z') {
                    count[0]++;
                } else if (c >= 'A' && c <= 'Z') {
                    count[1]++;
                } else if (c == ' ') {
                    count[3]++;
                } else {
                    count[2]++;
                }
            }

            for (int val : count) {
                sb.append(val).append(' ');
            }
            sb.append('\n');

        }
        System.out.println(sb);
    }
}
