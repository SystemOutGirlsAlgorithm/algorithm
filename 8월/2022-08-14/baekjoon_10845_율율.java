import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Queue;

// 큐 
public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cnt = Integer.parseInt(br.readLine().trim());
		Queue<Integer> q = new LinkedList<Integer>(); // 큐 구현
		
		for(int i = 0; i < cnt; i++) {
			String[] arr = br.readLine().trim().split(" "); // 공백으로 나눔
			String str = arr[0];
			
			if(str.equals("push")) {
				int n = Integer.parseInt(arr[1]);
				q.offer(n);
			}else if(str.equals("pop")) {
				if(q.isEmpty()) System.out.println("-1");
				else System.out.println(q.poll());
			}else if(str.equals("size")) {
				System.out.println(q.size());
			}else if(str.equals("empty")) {
				if(q.isEmpty()) System.out.println("1");
				else System.out.println("0");
			}else if(str.equals("front")) {
				if(q.isEmpty()) System.out.println("-1");
				else System.out.println(q.peek());
			}else if(str.equals("back")) {
				if(q.isEmpty()) System.out.println("-1");
				else {
					LinkedList<Integer> tmp = (LinkedList<Integer>) q; // 형변환
					ListIterator<Integer> it = tmp.listIterator();
					while(it.hasNext()) {
						it.next();
					}
					if(it.hasPrevious()) System.out.println(it.previous());
				}
				
			}
			
		}

	}

}
