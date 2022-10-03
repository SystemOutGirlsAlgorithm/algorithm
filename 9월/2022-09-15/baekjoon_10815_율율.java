import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		Set<Integer> set = new TreeSet<Integer>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++)
			set.add(Integer.valueOf(st.nextToken()));
		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<m; i++) {
			if(set.contains(Integer.valueOf(st.nextToken())))
					bw.write(1+" ");
			else
				bw.write(0+" ");
		}
		bw.flush();
		br.close();
		bw.close();
	}

}
