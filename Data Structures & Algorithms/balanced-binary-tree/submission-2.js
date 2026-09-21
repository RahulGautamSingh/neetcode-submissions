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
     * @return {boolean}
     */
    isBalanced(root) {
        return this.height(root) !== -1;
    }

    height(root){
        if(!root) return 0;

        let lh = this.height(root.left);
        if(lh === -1){
            return -1;
        }
        let rh = this.height(root.right);
        if(rh === -1){
            return -1;
        }

        if(Math.abs(lh - rh) > 1) return -1;

        return 1 + Math.max(lh, rh);
    }
}
