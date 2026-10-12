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
    diameterOfBinaryTree(root) {
        if(!root) return 0;

        let max = 0;

        function height(rooti){
            if(!rooti) return 0;

            const lh = height(rooti.left);
            const rh = height(rooti.right);

            const diam = lh + rh;
            if(max < diam) max = diam;


            return 1 + Math.max(lh, rh);
        }

        height(root);

        return max;        
    }
}
