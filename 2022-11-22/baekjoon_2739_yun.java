package baekjoon_221122;

import java.util.Scanner;

public class B2739 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		for(int i=1; i<=9; i++) {
			int multiply = n * i; 
			System.out.println(n+" * "+i+ " = "+multiply);
		}
	}
}
