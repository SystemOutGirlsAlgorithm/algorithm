import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;


public class Word_1181 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		String[] input = new String[N];
		
		for(int i=0;i<input.length;i++) {
			input[i] = br.readLine();
		}
				
		
		Arrays.sort(input);
		
		Arrays.sort(input,new Comparator<String>() {
			public int compare(String s1, String s2) {
				return s1.length() - s2.length();
			}
		});
		
		
		for(int i=0;i<input.length;i++) {
			if(i>0 && input[i].equals(input[i-1])) {}
			else {
				System.out.println(input[i]);
			}
		}
	}
}
