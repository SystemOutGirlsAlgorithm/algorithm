import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int[] cnt = new int[6];
        int[] piece = {1, 1, 2, 2, 2, 8};

        for(int i = 0; i < cnt.length; i++) {
            cnt[i] = sc.nextInt();
        }

        for(int i = 0; i < cnt.length; i++) {
            System.out.print(piece[i] - cnt[i] + " ");
        }
    }
}