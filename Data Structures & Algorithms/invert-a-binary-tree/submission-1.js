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
        let q = new Queue([root]);
        while(!q.isEmpty())
       { 
        const curr = q.pop();
        const newLeft = curr.right;
        const newRight = curr.left;

        curr.left = newLeft;
        curr.right = newRight;

        if(curr.left !== null){q.push(curr.left);}
        if(curr.right !== null){q.push(curr.right);}
       }

       return root;
    }
}
