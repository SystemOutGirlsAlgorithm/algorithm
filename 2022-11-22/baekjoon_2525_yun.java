package baekjoon_221122;

import java.util.Scanner;

public class B2525 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int h, m, mm;
		h = sc.nextInt();
		m = sc.nextInt();
		mm = sc.nextInt();
		
		h += mm / 60; //요리시간이 60분 이상이면 넘는 만큼 h에 더함
		m += mm % 60; //남는 분 m에 더함
		
		if(m>=60) {
			h += 1; //m이 60 이상이면 h 한시간 더하고
			m -= 60; //m은 60 뺌
		}
		
		if(h>=24) {
			h -= 24; //h가 24시 이상이면 24 뺌(24는 0으로 표기)
		}
		
		System.out.println(h+" "+m);
	}
}