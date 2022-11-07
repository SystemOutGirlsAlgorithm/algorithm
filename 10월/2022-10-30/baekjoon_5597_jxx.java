import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class baekjoon_5597_jxx {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[28];
        int[] arr2 = new int[30];

        for (int i = 0; i < arr.length; i++){
            int num = Integer.parseInt(br.readLine());
            arr2[num - 1] = -1;
        }
        for (int i = 0; i < arr2.length; i++){
            if (arr2[i] != -1){
                System.out.println(i + 1);
            }
        }
    }
}
