import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class baekjoon_5622_jxx {
    public static void main(String[] args) throws IOException {
/*
        if문을 이용한 풀이
*/
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int dial = 0;

        for (int i = 0; i < str.length(); i++){
            int ch = str.charAt(i);
            if (ch <= 'C') dial += 3; // ABC
            else if (ch <= 'F') dial += 4; // DEF
            else if (ch <= 'I') dial += 5; // GHI
            else if (ch <= 'L') dial += 6; // JKL
            else if (ch <= 'O') dial += 7; // MNO
            else if (ch <= 'S') dial += 8; // PQRS
            else if (ch <= 'V') dial += 9; // TUV
            else dial += 10; // WXYZ
        }
/*
        switch문을 이용한 풀이

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int dial = 0;

        for(int i = 0; i < str.length(); i++) {
            switch (str.charAt(i)) {
                case 'A': case 'B': case 'C': dial += 3; break;
                case 'D': case 'E': case 'F': dial += 4; break;
                case 'G': case 'H': case 'I': dial += 5; break;
                case 'J': case 'K': case 'L': dial += 6; break;
                case 'M': case 'N': case 'O': dial += 7; break;
                case 'P': case 'Q': case 'R': case 'S': dial += 8; break;
                case 'T': case 'U': case 'V': dial += 9; break;
                case 'W': case 'X': case 'Y': case 'Z': dial += 10; break;
            }
        }
*/
        br.close();
        System.out.println(dial);
    }
}