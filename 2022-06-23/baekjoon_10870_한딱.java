package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class fibonacci_11444 {
	public static void main(String args[]) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int N=Integer.parseInt(br.readLine());
		System.out.println(fibonacci(N));
		
	}
	
	public static int fibonacci(int n) {
		if(n==0) {
			return 0;
		}
		if(n==1) {
			return 1;
		}
		else {
			return fibonacci(n-1) + fibonacci(n-2);
		}
	}
}
