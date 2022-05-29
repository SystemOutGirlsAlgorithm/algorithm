import java.util.Scanner;

public class backjoon_1143_muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] arr = new int[5];

        for(int i = 0; i < arr.length; i++){
            arr[i] = scanner.nextInt();
        }

        int result= 1;
        int count = 0;
        while(true){
            for (int j : arr) {
                if (result % j == 0) {
                    count++;
                }
            }

            if(count > 2){
                System.out.println(result);
                break;
            }
            count = 0;
            result++;
        }
    }
}
