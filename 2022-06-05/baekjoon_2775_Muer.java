import java.util.Scanner;

public class baekjoon_2775_Muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int F[][] = new int[15][15];

        for(int i = 0; i < F.length; i++){
            F[i][1] = 1;
            F[0][i] = i;
        }

        for(int i = 1; i < F.length; i++){
            for(int j = 2; j < F.length; j++){
                F[i][j] = F[i][j-1] + F[i-1][j];
            }
        }

        int num = scanner.nextInt();

        for(int i = 0; i < num; i++){
            int num1 = scanner.nextInt();
            int num2 = scanner.nextInt();

            System.out.println(F[num1][num2]);
        }
    }
}
