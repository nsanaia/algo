/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
        
    public Node treeToDoublyList(Node root) {
        if (root == null) return null;        
        
        Node leftRes = treeToDoublyList(root.left);
        Node rigfhtRes = treeToDoublyList(root.right);
        
        root.left = root;
        root.right = root;
        
        return merge(merge(leftRes, root), rigfhtRes);
    }
    
    private Node merge(Node l, Node r) {
        if (l == null) return r;
        if (r == null) return l;
        
        Node lastL = l.left;
        lastL.right = r;
    
        Node lastR = r.left;
        lastR.right = l;
        
        r.left = lastL;
        l.left = lastR;
        
        return l;
    }
}