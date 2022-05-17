#include <bits/stdc++.h>

class Solution {
public:
	vector<pair<int, int>> NEIGHBORS{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
	
	struct Node {
		int row;
		int col;
	};

	Node getStartNode(vector<vector<char>>& grid) {
		for (int r = 0; r < grid.size(); r++) {
			for (int c = 0; c < grid[0].size(); c++) {
				if (grid[r][c] == '*') 
					return {r, c};
			}
		}
		
		return {0, 0};	
	}

	int getFood(vector<vector<char>>& grid) {
		int N = grid.size();
		int M = grid[0].size();
	
		queue<Node> nodes;
		nodes.push(getStartNode(grid));
		int level = 0;
		vector<vector<bool>> visited(N, vector<bool>(M, false));
		
		while (!nodes.empty()) {
			int levelSize = nodes.size();
			
			while (levelSize--) {
				auto curr = nodes.front();
				nodes.pop();
				
				if (grid[curr.row][curr.col] == '#')
					return level;
				
				if (visited[curr.row][curr.col])
					continue;
				
				visited[curr.row][curr.col] = true;
				
				for (auto n : 	NEIGHBORS) {
					int nextR = curr.row + n.first;
					int nextC = curr.col + n.second;
					
					if (nextR >= 0 && nextR < N 
						&& nextC >= 0 && nextC < M 
						&& grid[nextR][nextC] != 'X') {
						nodes.push(Node{nextR, nextC});	
					}
				}						
			}
            
            level++;
		}
		
		return -1;
	}
};