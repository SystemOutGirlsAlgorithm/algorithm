import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class baekjoon_4344_jxx {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int C = Integer.parseInt(br.readLine());
        StringTokenizer st;
        int sum = 0;
        int over = 0;

        for (int i = 0; i < C; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int[] arr = new int[a];
            for (int j = 0; j < a; j++){
                arr[j] = Integer.parseInt(st.nextToken());
                sum += arr[j];
            }
            double avg = (double) sum / a;
            for (int k = 0; k < a; k++){
                if(arr[k] > avg){
                    over++;
                }
            }
            String ratio2 = String.format("%.3f", (double) over / a * 100);
            System.out.println(ratio2 + "%");

            sum = 0;
            over = 0;
        }
    }
}