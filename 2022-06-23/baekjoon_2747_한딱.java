package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class fibonacci_11444 {
	public static void main(String args[]) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int N=Integer.parseInt(br.readLine());
		int sum=0;
		int f1=0;
		int f2=1;
		
		if(N==1) {sum=1;}
		for(int i=0;i<N-1;i++) {
			sum=f1+f2;
			f1=f2;
			f2=sum;
		}
		System.out.print(sum);
	}
	
	
}
