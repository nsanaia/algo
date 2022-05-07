#include <bits/stdc++.h>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<TreeNode*> nodes;
    nodes.push(A);

    vector<vector<int>> res;

    while (!nodes.empty()) {
        int levelCount = nodes.size(); 
        vector<int> level;

        for (int i = 0; i < levelCount; i++) {
            TreeNode* curr = nodes.front();
            nodes.pop();
            
            level.push_back(curr -> val);

            if (curr -> left != NULL)
                nodes.push(curr -> left);
            if (curr -> right != NULL)
                nodes.push(curr -> right);
        }

        res.push_back(level);
    }

    return res;
}