import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int N=Integer.parseInt(br.readLine());
		BigInteger sum=BigInteger.ONE;
		BigInteger f1=BigInteger.ZERO;
		BigInteger f2=BigInteger.ONE;
		
		for(int i=1;i<N;i++) {
			sum=f1.add(f2);
			f1=f2;
			f2=sum;
		}
		if(N==0) {sum=BigInteger.ZERO;}
		System.out.println(sum);
	}
}
