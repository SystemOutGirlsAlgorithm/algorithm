package baekjoon_221123;

import java.util.Scanner;

public class B10950 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t, a, b;
		
		t = sc.nextInt();
		
		for(int i=1; i<=t; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			
			System.out.println(a + b);
		}
	}
}
