import java.util.Scanner;

public class baekjoon_1233_muer {
    public static void main(String[] args) {
        // 3개의 주사위
        // 주사위마다 면 수가 다르다.

        // 3 2 3

        // 1 1 1 -> 3
        // 1 1 2 -> 4
        // 1 1 3 -> 5
        // 1 2 1 -> 4
        // 1 2 2 -> 5
        // 1 2 3 -> 6
        // 2 1 1 -> 4
        // 2 1 2 -> 5
        // 2 1 3 -> 6
        // 2 2 1 -> 5
        // 2 2 2 -> 6
        // 2 2 3 -> 7
        // 3 1 1 -> 5
        // 3 1 2 -> 6
        // 3 1 3 -> 7
        // 3 2 1 -> 6
        // 3 2 2 -> 7
        // 3 2 3 -> 8

        Scanner scanner = new Scanner(System.in);

        int s1 = scanner.nextInt();
        int s2 = scanner.nextInt();
        int s3 = scanner.nextInt();

        int[] arr = new int[81];

        for(int i = 1;  i <= s1; i++){
            for(int j = 1; j <= s2; j++){
                for(int k = 1; k <= s3; k++){
                    //System.out.println(i + ", " + j + ", "+ k);
                    arr[i+j+k]++;
                }
            }
        }

        int max = 0;
        int index = 0;

        for(int i = 0;  i < arr.length; i++){
            if(max < arr[i]){
                max = arr[i];
                index = i;
            }
        }

        System.out.println(index);

    }
}
