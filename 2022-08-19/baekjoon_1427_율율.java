import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
// 소트인사이드
public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine().trim();
		char[] arr = new char[str.length()];
		for(int i=0; i<str.length(); i++) {
			arr[i]=str.charAt(i);
		}
		
		Arrays.sort(arr);
		
		for(int i=str.length()-1; i>=0; i--) {
			System.out.print(arr[i]);
		}
		
		br.close();
	}

}
