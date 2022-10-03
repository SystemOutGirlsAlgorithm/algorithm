import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class baekjoon_3052_왕수 {
    public static void main(String[] args) {
        Scanner key = new Scanner(System.in);

        int arr[] = new int[10];

        for (int i = 0; i < 10; i++) {
            arr[i] = key.nextInt();
        }

        int na[] = new int[10];

        for (int i = 0; i < 10; i++) {
            na[i] = arr[i] % 42;
        }

        List<Object> Array = new ArrayList<Object>();

        for (int i = 0; i < 10; i++) {
            boolean iscontain = Array.contains(na[i]);
            if (iscontain != true)
                Array.add(na[i]);
        }

        System.out.println(Array.size());

    }
}
