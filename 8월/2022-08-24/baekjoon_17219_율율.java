import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int num1 = Integer.parseInt(st.nextToken());
		int num2 = Integer.parseInt(st.nextToken());
		
		HashMap<String, String> map = new HashMap<String, String>(num1);
		
		for(int i=0; i<num1; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			map.put(st.nextToken().trim(), st.nextToken().trim());
		}
		
		for(int i=0; i<num2; i++) {
			String domain = br.readLine().trim();
			bw.write(map.get(domain)+"\n");
		}
		
		bw.flush();
		br.close();
		bw.close();

	}

}
