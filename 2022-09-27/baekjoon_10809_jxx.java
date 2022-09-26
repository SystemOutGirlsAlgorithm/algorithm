import java.util.Scanner;

public class baekjoon_10809_jxx {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();

        for (char c = 'a'; c <= 'z'; c++){
            System.out.println(S.indexOf(c));
        }
    }
}