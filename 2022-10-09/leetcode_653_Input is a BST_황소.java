import java.util.HashSet;
import java.util.Set;
/* 너비우선탐색용 import
 * import java.util.LinkedList;
 * import java.util.Queue;
 * */

public class leetcode_653_Two Sum IV - Input is a BST_황소 {
    // 자력으로 풀기 실패 - 참고 사이트: https://ifuwanna.tistory.com/400
    public static void main(String[] args) {
        TreeNode root = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6, null, new TreeNode(7)));
        int k = 9;
        System.out.println(findTarget(root, k));
    }

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {} // redundant

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    // 깊이우선탐색 (이 문제에서는 깊이우선탐색이 조금 더 빠름)
    public static boolean findTarget(TreeNode root, int k) {
        Set<Integer> set = new HashSet<>();
        return dfs(root, set, k);
    }


    private static boolean dfs(TreeNode root, Set<Integer> set, int k) {
        if (root == null) return false;
        if (set.contains(k - root.val)) return true;
        set.add(root.val);
        return dfs(root.left, set, k) || dfs(root.right, set, k);
    }
    // 너비우선탐색
    /*public static boolean findTarget(TreeNode root, int k) {
        if (root == null) return false;
        Set<Integer> set = new HashSet<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode current = q.poll();
            if (set.contains(k - current.val)) return true;
            set.add(current.val);
            if (current.left != null) q.offer(current.left);
            if (current.right != null) q.offer(current.right);
        }
        return false;
    }*/
}