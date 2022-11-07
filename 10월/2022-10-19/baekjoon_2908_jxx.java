import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class baekjoon_2908_jxx {
    public static void main(String[] args) throws IOException {
/*
        substring()을 이용한 풀이

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String A = st.nextToken();
        String B = st.nextToken();

        String revA = A.substring(2, 3) + A.substring(1, 2) + A.substring(0, 1);
        String revB = B.substring(2, 3) + B.substring(1, 2) + B.substring(0, 1);
        int intRevA = Integer.parseInt(revA);
        int intRevB = Integer.parseInt(revB);
        System.out.println(Math.max(intRevA, intRevB));
        br.close();
*/

/*      StringBuilder 클래스의 reverse()를 이용한 풀이
*/
        Scanner sc = new Scanner(System.in);

		String a = sc.next();
		int aa = Integer.parseInt(new StringBuilder(a).reverse().toString());

		String b = sc.next();
		int bb = Integer.parseInt(new StringBuilder(b).reverse().toString());

		System.out.println(Math.max(aa, bb));

    }
}
