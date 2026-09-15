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
        let s = [root];
        while(s.length)
       { 
        const curr = s.pop();
        const newLeft = curr.right;
        const newRight = curr.left;

        curr.left = newLeft;
        curr.right = newRight;

        if(curr.left){s.push(curr.left);}
        if(curr.right){s.push(curr.right);}
       }

       return root;
    }
}
