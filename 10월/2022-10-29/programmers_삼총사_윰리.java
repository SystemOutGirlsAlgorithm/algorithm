import java.util.LinkedList;

class Solution {

    private static int count;

    public int solution(int[] number) {
        count = 0;

        combination3(number, new boolean[number.length], new LinkedList<>());

//        System.out.println("count = " + count);
        return count;
    }

    public void combination3(int[] number, boolean[] visited, LinkedList<Integer> nums) {
        if (nums.size() >= 3) {
//            System.out.println(nums);
            if (nums.stream().mapToInt(Integer::intValue).sum() == 0) {
                count++;
            }
            return;
        }

        for (int i = 0; i < number.length; i++) {
            if (visited[i]) {
                continue;
            }
            nums.add(number[i]);
            visited[i] = true;
            combination3(number, visited.clone(), new LinkedList<>(nums));
            nums.removeLast();
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        s.solution(new int[]{-2, 3, 0, 2, -5}); //2
        s.solution(new int[]{-3, -2, -1, 0, 1, 2, 3}); //5
        s.solution(new int[]{-1, 1, -1, 1}); //0
    }
}