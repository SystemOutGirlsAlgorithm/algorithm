import java.util.Scanner;

public class baekjoon_10950_왕수 {
    public static void main(String[] args) {
        Scanner key = new Scanner(System.in);
        int num = key.nextInt();
        int arr[] = new int[num];

        for (int i = 0; i < num; i++) {
            int a = key.nextInt();
            int b = key.nextInt();
            arr[i] = a + b;

        }

        for (int k : arr)
            System.out.println(k);

    }
}