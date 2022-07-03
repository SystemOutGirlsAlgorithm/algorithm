import java.util.Scanner;

public class baekjoon_7568_Muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[][] D = new int[N][2];

        for(int i = 0; i < N; i++){
            D[i][0] = scanner.nextInt();
            D[i][1] = scanner.nextInt();
        }

        for(int i = 0; i < N; i++){
            int score = 1;

            for(int j = 0; j < N; j++){
                if(j == i){
                    continue;
                }

                if(D[i][0] < D[j][0] && D[i][1] < D[j][1]){
                    score++;
                }
            }

            System.out.print(score+" ");
        }
    }
}
