import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		HashSet<Integer> setA = new HashSet<Integer>(a);
		HashSet<Integer> setB = new HashSet<Integer>(b);
		HashSet<Integer> setCha = new HashSet<Integer>();
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<a; i++) 
			setA.add(Integer.valueOf(st.nextToken()));
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<b; i++)
			setB.add(Integer.valueOf(st.nextToken()));
		
		Iterator<Integer> it = setB.iterator();
		while(it.hasNext()) {
			Integer tmp = it.next();
			if(!setA.contains(tmp)) setCha.add(tmp);
		}
			
		it = setA.iterator();
		while(it.hasNext()) {
			Integer tmp = it.next();
			if(!setB.contains(tmp)) setCha.add(tmp);
		}
		
		System.out.println(setCha.size());
		br.close();
	}

}
