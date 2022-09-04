import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine().trim());
		int cnt = 0;
		
		for(int i=0; i<n; i++) {
			String str = br.readLine().trim();
			int tmp = 0;
			for(int j=0; j<str.length(); j++) {
				if(str.indexOf(str.charAt(j))==j) {
					tmp = 0;
				}else {
					tmp++;
					if((str.indexOf(str.charAt(j))+tmp)!=j) {
						if(str.charAt(j)!=str.charAt(j-1)) {
							cnt++;
							break;
							
						}
					}
				}
			}
		}
		
		System.out.println(n-cnt);
		
		br.close();
	}

}
