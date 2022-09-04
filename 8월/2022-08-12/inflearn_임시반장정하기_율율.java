import java.util.Scanner;

public class Main {
	
	public int solution(int N, int[][] arr) {
		int answer=0;
		int max = Integer.MIN_VALUE;
		
		for(int i=1; i<N+1; i++) { 
			int cnt=0;
			for(int j=1; j<N+1; j++) { 
				for(int k=1; k<6; k++) { 
					if(arr[i][k]==arr[j][k]) {
						cnt++;
						break; 
					}
				}
			}
			if(cnt>max) { 
				max=cnt;
				answer=i;
			}
		}
		return answer;
	}

	public static void main(String[] args) {
		Main M = new Main(); 
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] arr = new int[N+1][6]; 
		for(int i=1; i<N+1; i++) { 
			for(int j=1; j<6; j++) { 
				arr[i][j]=sc.nextInt();
			}
		}
		
		System.out.println(M.solution(N, arr));
		sc.close();
	}
}// end of class