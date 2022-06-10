import java.util.Scanner;

public class baekjoon_11050_Muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int k = scanner.nextInt();

        System.out.println(factorial(n) / (factorial(n - k) * factorial(k)));
    }

    public static int factorial(int num){
        if(num  == 0){
            return 1;
        }

        return num * factorial(num -1);
    }
}
