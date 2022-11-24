import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Main {

    public void solution(int n, List<Integer> nums) {
        PriorityQueue<Integer> absHeap = new PriorityQueue<>((a, b) -> Math.abs(a) == Math.abs(b)? a - b : Math.abs(a) - Math.abs(b));

        for (Integer num : nums) {
            if (num == 0) {
                if (absHeap.isEmpty()) {
                    System.out.println(0);
                    continue;
                }
                System.out.println(absHeap.poll());
                continue;
            }
            absHeap.add(num);
        }
    }

    public static void main(String[] args) throws IOException {
        Main main = new Main();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        List<Integer> nums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            nums.add(Integer.parseInt(br.readLine()));
        }

        main.solution(n, nums);
    }
}