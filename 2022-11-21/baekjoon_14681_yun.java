package baekjoon_221121;

import java.util.Scanner;

public class B14681 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int x, y;
		
		x = sc.nextInt();
		y = sc.nextInt();
		
		if(x>=-1000 && x<=1000 && x!=0) {
			if(y>=-1000 && y<=1000 && y!=0) {
				if(x>0 && y>0) {
					System.out.println("1");
				}else if(x<0 && y>0) {
					System.out.println("2");
				}else if(x<0 && y<0) {
					System.out.println("3");
				}else if(x>0 && y<0) {
					System.out.println("4");
				}
			}
		}else {
			System.out.println("숫자를 다시 입력하세요.\n-1000 ≤ x ≤ 1000; x ≠ 0"
					+ "\n−1000 ≤ y ≤ 1000; y ≠ 0");
		}
	}
}
