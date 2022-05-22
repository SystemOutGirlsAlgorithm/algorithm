import java.util.Scanner;

public class baekjoon_10809_muer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] num = new int[26];

        String S = scanner.next();

        for(int i = 0; i < 26; i++){
            num[i] = -1;
        }

        int w;
        for(int i = 0; i < S.length(); i++){
            //System.out.println(S.charAt(i));
            w = S.charAt(i);
            //System.out.println(w);
            if(num[w-97] == -1){
                num[w-97] = i;
            }
        }

        for(int i = 0; i < 26; i++){
            System.out.print(num[i]+" ");
        }


    }
}
