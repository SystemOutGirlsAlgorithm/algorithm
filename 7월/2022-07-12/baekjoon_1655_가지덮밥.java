import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static final BufferedReader b = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(b.readLine());
        StringBuilder sb = new StringBuilder();

        PriorityQueue<Integer> min = new PriorityQueue<>((o1, o2) -> o1 - o2);
        PriorityQueue<Integer> max = new PriorityQueue<>((o1, o2) -> o2 - o1);

        for(int i = 0 ; i < n; i++){
            int num = Integer.parseInt(b.readLine());

            if(min.size() == max.size()) max.offer(num);
            else min.offer(num);

            if(!min.isEmpty() && !max.isEmpty())
                if(min.peek() < max.peek()){
                    int tmp = min.poll();
                    min.offer(max.poll());
                    max.offer(tmp);
                }

            sb.append(max.peek() + "\n");
        }
        System.out.println(sb);
    }
}