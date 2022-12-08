package baekjoon.string;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class baekjoon_10808_캐시 {
    public static void main(String[] args) throws IOException {
        //1. 단어 s 입력
        //2. 알파벳 배열 생성
        //3. 각 배열에 알파벳 갯수 담기? 문자열 > 숫자형.. 아스키코드 a는 97
        //4. 스트링빌더로 출력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int[] arr = new int[26];

        for (int i=0; i<s.length(); i++) {
            arr[(int)s.charAt(i) - 97] += 1;
        }

        StringBuilder sb = new StringBuilder();
        for (int i=0; i<arr.length; i++) {
            sb.append(arr[i]).append(" ");
        }
        System.out.println(sb);
    }
}
