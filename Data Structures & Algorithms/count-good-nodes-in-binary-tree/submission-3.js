/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     constructor(val = 0, left = null, right = null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    /**
     * @param {TreeNode} root
     * @return {number}
     */
    goodNodes(root) {
        return this.helper(root, root.val);
    }

    helper(root, max){
        if(!root) return 0;

        if(root.val >= max){
            return 1 + this.helper(root.left, root.val) + this.helper(root.right, root.val);
        } else {
            return this.helper(root.left, max) + this.helper(root.right, max);
        }
    }
}
