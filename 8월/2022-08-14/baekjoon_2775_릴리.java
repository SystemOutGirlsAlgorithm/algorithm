import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        int[][] apt = new int[15][15];
        
        for(int i = 0; i <= 14; i++) {
            apt[i][1] = 1; 
            apt[0][i] = i;
        }

        // 1~14층
        for(int i = 1; i <= 14; i++) {
            // 2~14호
            for(int j = 2; j <= 14; j++) {
                apt[i][j] = apt[i][j - 1] + apt[i - 1][j];
            }
        }

        for(int i = 0; i < T; i++) {
            int k = Integer.parseInt(br.readLine());
            int n = Integer.parseInt(br.readLine());

            System.out.println(apt[k][n]);
        }    
    }
}