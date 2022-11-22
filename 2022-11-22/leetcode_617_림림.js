/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {TreeNode}
 */
 var mergeTrees = function(root1, root2) {
    // root1이 null이거나 root2가 null일 때, root1 또는 root2 반환
    if (root1 === null || root2 === null) {
        return root1 || root2;
    } 
    const root = new TreeNode(root1.val + root2.val); // 위에 TreeNode 함수
    const left = mergeTrees(root1.left, root2.left); // left끼리 merge
    const right = mergeTrees(root1.right, root2.right); // right끼리 merge
    root.left = left;
    root.right = right;
    return root;
};