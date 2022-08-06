import java.util.*;

public class Main {
	public ArrayList<Integer> solution(int n, int m, int[] a, int[] b){
		ArrayList<Integer> answer = new ArrayList<>();
		int p1=0, p2=0;
		while(p1<n && p2<m) { // 둘 다 true일 때 true이다.
			if(a[p1]<b[p2]) answer.add(a[p1++]); // 후위연산
			else answer.add(b[p2++]); // a[p1]>=b[p2]일 때, 같을 때는 둘 중에 아무거나 넣어도 상관 없어서
		}
		
		while(p1<n) answer.add(a[p1++]); // p1이 남아 있으면 while(true)면 반복
		while(p2<m) answer.add(b[p2++]); // p2가 남아 있으면
		
		return answer;
	}

	public static void main(String[] args) {
		Main T = new Main();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for(int i=0; i<n; i++) {
			a[i]=sc.nextInt();
		}
		int m = sc.nextInt();
		int[] b = new int[m];
		for(int i=0; i<m; i++) {
			b[i]=sc.nextInt();
		}
		
		for(int x:T.solution(n, m, a, b)) System.out.print(x+" ");
		sc.close();
		
	}

}