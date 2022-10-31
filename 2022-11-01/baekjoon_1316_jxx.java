import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class baekjoon_1316_jxx {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int cnt = 0; // 그룹 단어 개수
        String str;

        for (int i = 0; i < N; i++){
            str = br.readLine();
            boolean[] arr = new boolean[26]; // 알파벳 사용 내역
            boolean bool = true; // 그룹 단어 인지

            for (int j = 0; j < str.length(); j++){
                int idx = str.charAt(j) - 'a';

                if (arr[idx]) { // 이전에 사용한적이 있는 문자라면
                    if (str.charAt(j) != str.charAt(j - 1)) { // 이전 문자와 연속되지 않는다면
                        bool = false; // 그룹 단어가 아님
                        break;
                    }
                } else { // 이전에 사용한적이 없는 문자라면
                    arr[idx] = true; // 문자 사용 체크
                }
            }

            if (bool) {
                cnt++;
            }
        }
        br.close();
        System.out.println(cnt);
    }
}
