import java.util.Scanner;

public class Main {
	public int solution(int n, int k, int[] arr) { // 인스턴스 메서드
		int answer=0, sum=0; 
		
		for(int i=0; i<k; i++)
			sum+=arr[i];
		answer=sum; 
		//밀고가기(sliding)
		for(int i=k; i<n; i++) {
			sum+=(arr[i]-arr[i-k]);
			answer=Math.max(answer, sum);
		}
		return answer;
	}
	
	public static void main(String[] args) { // static 메서드
		Main T = new Main(); // 인스턴스 생성
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] arr = new int[n];
		for(int i=0; i<n; i++) 
			arr[i]=sc.nextInt();
		System.out.println(T.solution(n, k, arr));
		sc.close();
	}
}