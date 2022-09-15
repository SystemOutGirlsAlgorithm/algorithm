import java.util.Scanner;

public class Main {
	public static String Solution(String s) {
		String answer="";
		String[] sArr = s.split(" ");
		int min=Integer.MAX_VALUE, max=Integer.MIN_VALUE;
		for(int i=0; i<sArr.length; i++) {
			int tmp = Integer.parseInt(sArr[i]);
			min=Math.min(tmp, min);
			max=Math.max(tmp, max);
		}
		
		answer=min+" "+max;
		return answer;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine().trim();
		Solution(s);
		sc.close();
	}

}
