import java.util.Scanner;

public class baekjoon_1546_jxx {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = 0;
        int sum = 0;
        double avg = 0;
        int[] arr = new int[N];

        for(int i = 0; i < N; i++){
            arr[i] = sc.nextInt();
            if (arr[i] > M){
                M = arr[i];
            }
            sum += arr[i];
        }
        avg = (double)sum / M * 100 / N;
        System.out.println(avg);
    }
}