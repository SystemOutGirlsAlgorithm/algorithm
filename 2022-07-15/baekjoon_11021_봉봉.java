import java.io.*;
import java.util.StringTokenizer;



public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st ;

        int n = Integer.parseInt(bf.readLine());

        for(int i=0;i<n;i++){
            st  = new StringTokenizer(bf.readLine());
            int num = Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken());

            bw.write(String.format("Case #%d: ",i+1)+num+"\n");
        }

        bw.close();


    }
}