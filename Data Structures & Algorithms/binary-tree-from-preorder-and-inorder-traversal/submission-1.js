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
     * @param {number[]} preorder
     * @param {number[]} inorder
     * @return {TreeNode}
     */
    buildTree(preorder, inorder) {

        let mm = new Map();
        for(let i=0; i<inorder.length; i++) { mm.set(inorder[i], i)};
        let preIdx = 0;

        
        function helper(leftIn, rightIn){

        if (leftIn >= rightIn) return null;

        let node = new TreeNode(preorder[preIdx++]);
        let rootIndex = mm.get(node.val);

        node.left = helper(leftIn, rootIndex);
        node.right = helper(rootIndex + 1, rightIn);
        return node;
        }

        return helper(0, inorder.length);

    }
    
}
