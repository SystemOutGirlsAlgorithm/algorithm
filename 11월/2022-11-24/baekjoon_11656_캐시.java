package baekjoon.string;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//접미사 배열
public class baekjoon_11656_캐시 {
    //1. 문자열 자르기하면 될거 같음
    //2. 그 문자열 자른거를 배열에 넣고
    //3. 그 배열을 정렬하고
    //4. 출력
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();

        String[] arr = new String[S.length()];
        for (int i=0; i<S.length(); i++) {
            arr[i] = S.substring(i, S.length());
        }

        Arrays.sort(arr);

        StringBuilder sb = new StringBuilder();
        for (String val : arr) {
            sb.append(val).append('\n');
        }
        System.out.print(sb);
    }
}
