import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class chocolate_2163 {
	public static void main(String args[]) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine()," ");
		
		int N=Integer.parseInt(st.nextToken());
		int M=Integer.parseInt(st.nextToken());
		
		if(N==1 && M==1) {
			System.out.println(0);
		}
		else if(N==1 && M>1) {
			System.out.println(M-1);
		}
		else if(N>1 && M==1) {
			System.out.println(N-1);
		}
		else {
			System.out.println((N-1)*M+(M-1));
		}
	}	
}
