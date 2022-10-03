import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class baekjoon_8958_jxx {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int caseNum = Integer.parseInt(br.readLine());
        int sum = 0;

        for (int i = 0; i < caseNum; i++){
            String ox = br.readLine();
            String[] arr = ox.split("X"); // x를 기준으로 문자열을 자르고
            for (int j = 0; j < arr.length; j++){
                if (!arr[j].equals("")){
                    sum += arr[j].length() * ( arr[j].length()+1 ) / 2;
                }
            }
            System.out.println(sum);
            sum = 0;
        }
    }
}