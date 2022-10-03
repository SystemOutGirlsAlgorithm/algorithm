import java.util.Scanner;

public class baekjoon_n_왕수 {
    public static void main(String[] args) {
        Scanner key = new Scanner(System.in);

        String arr[] = new String[key.nextInt()];

        for (int i = 0; i < arr.length; i++)
            arr[i] = key.next();

        int[] score_arr = new int[arr.length];

        for (int j = 0; j < arr.length; j++) {
            int score = 0;
            int plus = 1;

            for (int i = 0; i < arr[j].length(); i++) {
                if (arr[j].charAt(i) == 'O') {
                    score += plus;
                    plus += 1;
                }

                else if (arr[j].charAt(i) == 'X')
                    plus = 1;

            }
            score_arr[j] = score;
        }

        for (int s : score_arr)
            System.out.println(s);
    }
}
