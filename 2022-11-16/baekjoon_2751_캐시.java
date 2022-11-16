package baekjoon.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//오름차순으로 정렬하는 프로그램
public class baekjoon_2751_캐시 {
    public static void main(String[] args) throws IOException {
        //1. 개수 n 입력
        //2. 숫자 입력, 줄바꿈으로
        //3. 오름차순 정렬하기
        //4. 출력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i=0; i<n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(arr); 

        StringBuilder sb = new StringBuilder();
        for (int i : arr)
            sb.append(i).append("\n");

        System.out.print(sb);
    }
}
