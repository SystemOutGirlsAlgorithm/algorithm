import java.util.Scanner;

public class baekjoon_3052_Muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] num = new int[10];
        int[] count = new int[42];
        int res = 0;

        for(int i = 0; i < num.length; i++){
            num[i] = scanner.nextInt();
        }

        for (int j : num) {
            count[j % 42]++;
        }

        for(int i = 0; i < 42; i++){
            if(count[i] != 0){
                res++;
            }
        }

        System.out.println(res);
    }
}
