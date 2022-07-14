/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return lca(root, p, q).res;
    }
    
    private NodeData lca(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return new NodeData();
        
        NodeData leftRes = lca(root.left, p, q);
        if (leftRes.res != null) return leftRes;
        
        NodeData rightRes = lca(root.right, p, q);
        if (rightRes.res != null) return rightRes;
             
        NodeData res = new NodeData();
        res.found += leftRes.found + rightRes.found;
        
        if (root == p || root == q) res.found++;
        
        if (res.found == 2) res.res = root;            
            
        return res;
    } 
    
    class NodeData {
        TreeNode res;
        int found = 0;
    }
}