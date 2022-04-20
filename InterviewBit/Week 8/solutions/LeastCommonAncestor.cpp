/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Info {
    TreeNode* parent;
    int found;
};

Info dfs(TreeNode* A, int B, int C) {
    if (A == NULL)
        return {NULL, 0};

    Info res{A, 0};
    if (A -> val == B)  res.found++;
    if (A -> val == C)  res.found++;
    
    if (res.found == 2)
        return res;

    auto leftRes = dfs(A -> left, B, C);
    if (leftRes.found == 2)
        return leftRes;

    res.found += leftRes.found;

    auto rightRes = dfs(A -> right, B, C);
    if (rightRes.found == 2)
        return rightRes;

     res.found += rightRes.found;
    
    return res;    
}

int Solution::lca(TreeNode* A, int B, int C) {
    auto res = dfs(A, B, C);
    return res.found == 2 ? (res.parent -> val) : -1;
}
