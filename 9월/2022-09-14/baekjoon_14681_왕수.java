import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        Scanner key = new Scanner(System.in);

        int x = key.nextInt();
        int y = key.nextInt();

        if (x > 0)
            if (y > 0)
                System.out.println(1);
            else
                System.out.println(4);

        else if (y > 0)
            System.out.println(2);
        else
            System.out.println(3);

    }
}