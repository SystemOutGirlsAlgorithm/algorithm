import java.util.Scanner;

public class baekjoon_3003_jxx {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] chess = {1, 1, 2, 2, 2, 8};
        for(int i = 0; i < 6; i++){
            int input = sc.nextInt();
            System.out.print(chess[i] - input + " ");
        }
    }
}