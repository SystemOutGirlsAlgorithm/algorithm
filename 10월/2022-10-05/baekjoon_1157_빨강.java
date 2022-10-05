import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main (String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String string = br.readLine().toUpperCase();

        int[] count = new int[25];

        for (int i=0; i<string.length(); i++) {
            int num = string.charAt(i)-'A';
            count[num-1]++;
        }

        int max = 0;
        char maxAlphabet = '?';

        for (int i = 0; i < count.length; i++){
            if (count[i] > max) {
                max = count[i];
                maxAlphabet = (char)(i+'A'+1);
            } else if (max == count[i]) {
                maxAlphabet = '?';
            }
        }
        System.out.println(maxAlphabet);
    }
}
