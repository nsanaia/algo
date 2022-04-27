/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #define MOD 1003

bool isLeaf(TreeNode* A) {
    return A -> left == NULL && A -> right == NULL;
}

int sumNumbersHelper(TreeNode* A, int soFar) {
    int currVal = A -> val;
    soFar = (soFar + currVal) % MOD;;

    if (isLeaf(A))
        return soFar;

    soFar = (soFar * 10) % MOD; 
    
    int res = 0;
    if (A -> left != NULL)
        res += sumNumbersHelper(A -> left, soFar);

    if (A -> right != NULL)
        res = (res + sumNumbersHelper(A -> right, soFar)) % MOD;

    return res;
}

int Solution::sumNumbers(TreeNode* A) {
    return sumNumbersHelper(A, 0);
}
