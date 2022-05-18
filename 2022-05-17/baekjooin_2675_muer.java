import java.util.Scanner;

public class baekjooin_2675_muer {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();

        int[] R = new int[T];
        String[] S = new String[T];

        for(int k = 0;  k < T; k++) {
            R[k] = scanner.nextInt();

            S[k] = scanner.next();

            //System.out.println(S[k].length());
        }

        int l;

        for(int k = 0;  k < T; k++) { // 2
            for (int i = 0; i < S[k].length(); i++) { // abc // 3
                for (int j = 0; j < R[k]; j++) { // 3
                    l = i+1;
                    if(l <= S[k].length()) {
                        System.out.print(S[k].substring(i,l));
                    }
                }
            }
            System.out.println();
        }
    }
}
