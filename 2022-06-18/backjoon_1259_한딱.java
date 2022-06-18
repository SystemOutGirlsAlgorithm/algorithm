import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Palindrome_1259 {
	public static void main(String args[]) throws IOException {
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		
		int input;
		int[] arr=new int[5];
		
		while(true) {
			Arrays.fill(arr, 0);
			
			input=Integer.parseInt(bf.readLine());
			if(input==0) {
				break;
			}
			int n=0;
			
			while(input>0) {
				arr[n]=input%10;
				input/=10;
				n++;
			}
			
			int check=0;
			for(int i=0;i<n/2;i++) {
				int last=n;
				
				if(arr[i]!=arr[last-1-i]) check++; 
			}
			
			if(check==0) {
				bw.write("yes\n");
			}
			else {
				bw.write("no\n");
			}
		}
		
		bw.flush();
		bw.close();
	}
}
