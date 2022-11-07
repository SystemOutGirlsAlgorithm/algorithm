import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {
    private static List<List<Integer>> results;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        results = new ArrayList<>();
        Arrays.sort(candidates);
        makeCombination(candidates, new boolean[candidates.length], target, new LinkedList<>());
        return results;
    }

    public void makeCombination(int[] candidates, boolean[] visited, int target, List<Integer> nums) {
        if (target <= 0) {
//            System.out.println(nums);
            results.add(nums);
            return;
        }

        for (int i = 0; i < candidates.length; i++) {
            if (visited[i]) {
                continue;
            }
            if (target < candidates[i]) {
                break;
            }
            //target - candis[i] >= 0
            nums.add(candidates[i]);
            makeCombination(candidates, visited.clone(), target - candidates[i], new LinkedList<>(nums));
            nums.remove(nums.size() - 1);
            visited[i] = true;
        }
    }
}