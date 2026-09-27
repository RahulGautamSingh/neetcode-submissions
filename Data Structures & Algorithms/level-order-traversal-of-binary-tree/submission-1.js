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
     * @return {number[][]}
     */
    levelOrder(root) {
        if(!root) return [];
       let q = [root];
       let res = [];

       while(q.length){

        let currentLevelNodes = [];
        let currentLevelNodesVal = [];
        while(q.length){
            let node = q.shift();
            currentLevelNodesVal.push(node.val);
           if(node.left) currentLevelNodes.push(node.left);
            if(node.right) currentLevelNodes.push(node.right);
        }

        res.push(currentLevelNodesVal);

        q = currentLevelNodes;
       }


return res;
        
    }
}
