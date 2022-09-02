import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine().trim());
		for(int i=0; i<n; i++) {
			String str = br.readLine();
			Stack<Character> st = new Stack<Character>();
			boolean flag = true;
			for(int j=0; j<str.length(); j++) {
				char c = str.charAt(j);
				switch (c) {
				case '(':
					st.push(c);
					break;

				case ')':
					if(st.isEmpty()) flag = false;
					else st.pop();
					break;
				} // switch-case
				if(!flag) break;
			} // for j
			if(!st.isEmpty()) flag=false;
				
			if(flag) System.out.println("YES");
			else System.out.println("NO");
		} // for i

	} // main()

} // class
