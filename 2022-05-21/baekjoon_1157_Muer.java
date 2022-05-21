import java.util.Scanner;

public class baekjoon_1157 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String word = scanner.next();

        int[] num = new int[26];
        // 0 ~ 26
        // 65 ~ 90 -> -65
        int w;
        for(int i = 0; i < word.length(); i++){
            w = word.charAt(i);
            //System.out.println(w);

            if( 97 <= w && w <= 122){
                w -= 32;
            }
            //System.out.println(w);
            num[w-65] += 1;
        }

        int max = 0;
        char m = '0'; 
        
        for(int i = 0;  i < num.length; i++){
            if(max < num[i]){
                max = num[i];
                m = (char) (i+65);
            }else if (max == num[i]){
                m = '?';
            }
        }

        System.out.println(m);
    }
}
