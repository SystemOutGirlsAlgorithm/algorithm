import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class baekjoon_2839_jxx {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int i = 0;

        while (true){
            if ((N == 4) || (N % 3 == 0 && N % 5 == 0 && N % 15 != 0)){
                System.out.println("-1");
                break;
            } else if ((N - 3 * i) % 5 == 0){
                System.out.println(i + (N - 3 * i) / 5);
                break;
            } else {
                if (N - 3 * i < 0){
                    System.out.println("-1");
                    break;
                } else {
                    i++;
                }
            }
        }
        br.close();
    }
}
