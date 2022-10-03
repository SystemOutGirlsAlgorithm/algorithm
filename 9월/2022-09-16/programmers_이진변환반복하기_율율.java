import java.util.Scanner;

public class Main {
	public static int[] solution(String s) {
		int[] answer = new int[2];
		while(true) {
			answer[1] += s.length();
			s = s.replace("0", "");
			answer[1] -= s.length();
			s = Integer.toBinaryString(s.length());
			answer[0]++;
			if(s.equals("1")) break;
		}
		return answer;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		solution(str);
		sc.close();
	}

}
