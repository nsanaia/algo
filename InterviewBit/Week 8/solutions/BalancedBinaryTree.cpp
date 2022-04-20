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

pair<bool, int> isBalancedHelper(TreeNode* A) {
	if (A == NULL)
		return {true, 0};
	
	auto leftRes = isBalancedHelper(A -> left);
	if (!(leftRes.first))
		return {false, 0};
	
	auto rightRes = isBalancedHelper(A -> right);	
	if (!(rightRes.first))
		return {false, 0};
	
	int leftHeight = leftRes.second;
	int rightHeight = rightRes.second;

	bool isBal = abs(leftHeight - rightHeight) < 2;
	int height = max(leftHeight, rightHeight) + 1;

	return {isBal, height};
}

int Solution::isBalanced(TreeNode* A) {
	return isBalancedHelper(A).first;
}
