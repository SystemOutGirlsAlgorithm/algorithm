package baekjoon.string;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class baekjoon_10809_캐시 {
    public static void main(String[] args) throws IOException {
        //1. 단어 s 입력
        //2. 알파벳 배열 생성
        //3. 배열 초기값 -1
        //4. 배열에는 알파벳 위치를 삽입!
        //5. for문 배열 출력

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int[] arr = new int[26];

        for (int i=0; i<arr.length; i++) { //초기값 -1로
            arr[i] = -1;
        }

        for (int i=0; i<s.length(); i++) { //배열 삽입 > 첫 위치
            if (arr[(int)s.charAt(i) - 97] == -1) {
                arr[(int)s.charAt(i) - 97] = i;
            }
        }

        for(int val : arr) { //배열 출력
            System.out.print(val + " ");
        }

    }
}
