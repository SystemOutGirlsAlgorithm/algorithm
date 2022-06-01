import java.util.Scanner;

public class baekjoon_2609_Muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();

        System.out.println(max(num1, num2)); // 24, 18
        System.out.println(min(num1, num2));
    }

    public static int max(int num1, int num2) {
        while (num2 != 0) {
            int res = num1 % num2;
            num1 = num2;
            num2 = res;
        }
        return num1;
    }

    public static int min(int num1, int num2) {
        return num1 * num2 / max(num1, num2);
    }
}
