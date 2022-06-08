import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		int N=Integer.parseInt(bf.readLine());
		int[] arr=new int[N];
		int input;
		int top=-1;
		for(int i=0;i<N;i++) {
			input=Integer.parseInt(bf.readLine());
			
			if(input==0) {
				arr[top]=0;
				top--;
			} 
			else {
				top++;
				arr[top]=input;
			}
		}
		
		int sum=0;
		
		for(int i=0;i<arr.length;i++) {
			sum+=arr[i];
		}
		
		System.out.println(sum);
	}
}
