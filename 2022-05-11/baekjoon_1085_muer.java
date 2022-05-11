import java.util.Scanner;

public class baekjoon_1085_muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int w = scanner.nextInt();
        int h = scanner.nextInt();

        // 내 위치는 (x, y)
        int a = Math.min(w - x, x);
        int b = Math.min(h - y, y);
        //System.out.println(a);
        //System.out.println(b);

        int result = Math.min(a, b);

        System.out.println(result);
    }
}
