
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class baekjoon_4344 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        Integer number = Integer.parseInt(br.readLine());

        for(int i=0;i<number;i++){
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());

            ArrayList<Integer> arr = new ArrayList<Integer>();

            int hap = 0;
            int num =0;
            float percent = 0;
            float mean = 0 ;


            for(int k=0;k<n;k++){
                int tmp = Integer.parseInt(st.nextToken());
                arr.add(tmp);
                hap += tmp;
            }

            mean = hap / n;

            for(int k:arr){
                if(mean<=k){
                    num+=1;
                }
            }

            System.out.println();





        }

    }
}
