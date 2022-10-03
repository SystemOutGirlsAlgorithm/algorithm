import java.io.*;

public class baekjoon_1110_jxx {
    public static void main(String[] args) throws IOException {
        // 더하기 사이클
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        String storage = input;
        int N = Integer.parseInt(input);
        if(N < 10){
            input = Integer.toString(N) + "0";
            storage = input;
        }
        int i = 0;

        while (true){
            String left = input.substring(0, 1); // 주어진 수의 십의 자리 수
            String right = input.substring(input.length() - 1); // 주어진 수의 일의 자리 수
            int A = Integer.parseInt(left); // A 저장
            int B = Integer.parseInt(right); // B 저장
            String plus = Integer.toString(A + B);
            String plusRight = plus.substring(plus.length() - 1);
            input = right + plusRight;
            i++;
            if(input.equals(storage)){
                System.out.println(i);
                break;
            }
        }
    }
}
