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
     * @return {TreeNode}
     */
    invertTree(root) {
        // create tree from array
        
        if(!root) return null;
        const newLeft = this.invertTree(root.right);
        const newRight = this.invertTree(root.left);

        root.left = newLeft;
        root.right = newRight;

        return root;
    }
}
