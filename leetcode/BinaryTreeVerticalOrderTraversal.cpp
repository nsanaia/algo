#include <bits/stdc++.h>

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

	vector<vector<int>> verticalOrder(TreeNode* root) {
		unordered_map<int, vector<int>> res;
		verticalOrderHelper(root, res);
		return getSortedValuesByKey(res);
	}
	
	void verticalOrderHelper(TreeNode* root, unordered_map<int, vector<int>>& answer) {
        queue<pair<TreeNode *, int>> nodes;
        nodes.push(make_pair(root, 0));
        
		while (!nodes.empty()) {
            auto curr = nodes.front();
            TreeNode* currNode = curr.first;
            int currIdx = curr.second;
            nodes.pop();
            
            if (currNode == NULL)
                continue;
            
            answer[currIdx].push_back(currNode -> val);
            
            nodes.push(make_pair(currNode -> left, currIdx - 1));
            nodes.push(make_pair(currNode -> right, currIdx + 1));
        }
	}
	
	vector<vector<int>> getSortedValuesByKey(unordered_map<int, vector<int>> map) {
		vector<vector<int>> res;
		
        int minIdx = INT_MAX;
        int maxIdx = INT_MIN;
        
		for (auto& p : map) {
			minIdx = min(minIdx, p.first);
            maxIdx = max(maxIdx, p.first);
		}
		
		for (int i = minIdx; i <= maxIdx; i++) {
			res.push_back(map[i]);
		}
		
		return res;
	}
};