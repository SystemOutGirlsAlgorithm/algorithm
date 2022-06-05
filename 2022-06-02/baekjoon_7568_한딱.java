import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Ejdcl_7568 {
 public static void main(String args[]) throws IOException {
	 BufferedReader br=new BufferedReader(new InputStreamReader (System.in));
	 StringTokenizer st=new StringTokenizer(br.readLine());
	 
	 int N=Integer.parseInt(st.nextToken());
	 int[][] ejdcl=new int [N][2];
	 
	 for(int i=0;i<N;i++) {
		 st=new StringTokenizer(br.readLine());
		 for(int j=0;j<2;j++) {
			 ejdcl[i][j]=Integer.parseInt(st.nextToken());
		 }
	 }
	 
	 for(int i=0;i<N;i++) {
		 int rank=1;
		 for(int j=0;j<N;j++) {
			 if(ejdcl[i][0]<ejdcl[j][0] && ejdcl[i][1]<ejdcl[j][1]) rank++;
		 }
		 System.out.print(rank+" ");
	 }
	 
	
 }
}
