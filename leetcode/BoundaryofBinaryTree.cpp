/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void boundaryOfBinaryTreeHelper(TreeNode* root, bool isLeft, bool isRight, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        
        if (root -> left == NULL && root -> right == NULL) {
            res.push_back(root -> val);
            return;
        }
        
        if (isLeft) {
            res.push_back(root -> val);
        }
        
        boundaryOfBinaryTreeHelper(root -> left, isLeft, isRight && root -> right == NULL, res);
        boundaryOfBinaryTreeHelper(root -> right, isLeft && root -> left == NULL, isRight, res);
        
        if (isRight) {
            res.push_back(root -> val);
        }
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        
        vector<int> res{root -> val};
        boundaryOfBinaryTreeHelper(root -> left, true, false, res);
        boundaryOfBinaryTreeHelper(root -> right, false, true, res);
        return res;
    }
};