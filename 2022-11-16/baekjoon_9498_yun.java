package baekjoon_221116;

import java.util.Scanner;

public class B9498 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int score;
		
		score = sc.nextInt();
		
		if(score>=0 & score<=100) {			
			if(score>=90 & score<=100) {
				System.out.println("A");
			}else if(score>=80 & score<=89) {
				System.out.println("B");
			}else if(score>=70 & score<=79) {
				System.out.println("C");
			}else if(score>=60 & score<=69) {
				System.out.println("D");
			}else {
				System.out.println("F");
			}
		}else {
			System.out.println("시험점수를 다시 입력하세요. 시험 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수");
		}
	}
}
