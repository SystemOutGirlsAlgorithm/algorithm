import java.util.Scanner;

public class baekjoon_1075_muer {

    public static void main(String[] args) {
       Scanner scanner = new Scanner(System.in);

       int num = scanner.nextInt(); // 100보다 크기가 크다.
       int n = scanner.nextInt(); // 100보다 작거나 같다

       num -= (num % 100);

       //System.out.println("num = " + num);
       while (num % n != 0) {
           //System.out.println("num = " + num);
           num++;
       }
       
       System.out.printf("%02d", (num%100));
    }

}
