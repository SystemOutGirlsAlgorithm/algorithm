import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		System.out.println(fi(n));
			
	}
	public static int fi(int n) {
		if(n==0) {
			return 0;
		} else if(n ==1) {
			return 1;
		}
		return fi(n-1)+fi(n-2);
	}
  
}