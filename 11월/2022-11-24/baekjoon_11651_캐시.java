package baekjoon.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

//좌표 정렬하기 2
public class baekjoon_11651_캐시 {
    public static void main(String[] args) throws IOException {
        //1. 점의 개수 n입력
        //2. x좌표 y좌표 입력
        //3. y좌표 오름차순으로 정렬
        //    - y좌표 같으면 x좌표 오름차순으로 정렬
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());

        int[][] arr = new int[n][2];

        for (int i = 0; i < n; i++) {
            StringTokenizer str = new StringTokenizer(br.readLine(), " ");
            arr[i][0] = Integer.parseInt(str.nextToken());
            arr[i][1] = Integer.parseInt(str.nextToken());
        }

        Arrays.sort(arr, (a1, a2) -> {
            if(a1[1] == a2[1]) { //y가 같다면 x끼리 비교
                return a1[0] - a2[0];
            } else {
                return a1[1] - a2[1];
            }
        });

        for (int i=0; i<n; i++) {
            sb.append(arr[i][0]).append(' ').append(arr[i][1]).append('\n');
        }

        System.out.println(sb);
    }
}
