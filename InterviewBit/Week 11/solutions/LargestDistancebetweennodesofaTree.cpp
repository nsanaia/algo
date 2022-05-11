struct NodeInfo {
	int maxDist;
	int depth;
};

NodeInfo solveHelper(int root, vector<vector<int>>& graph);
vector<vector<int>> getGraph(vector<int> &A);
int getRoot(vector<int> &A);


int Solution::solve(vector<int> &A) {
    auto graph = getGraph(A);
    return solveHelper(getRoot(A), graph).maxDist;
}

NodeInfo solveHelper(int root, vector<vector<int>>& graph) {
	int firstDepth = 0;
	int secondDepth = 0;
	
	int maxDist = 0;

	for (auto child : graph[root]) {
		auto currRes = solveHelper(child, graph);
		
		maxDist = max(maxDist, currRes.maxDist);
		
		if (currRes.depth > firstDepth) {
			secondDepth = firstDepth;
			firstDepth = currRes.depth;
		} else if (currRes.depth > secondDepth) {
			secondDepth = currRes.depth;
		}
	}
	
	maxDist = max(firstDepth + secondDepth, maxDist);
	
	return {maxDist, firstDepth + 1};
}

vector<vector<int>> getGraph(vector<int> &A) {
	vector<vector<int>> res(A.size());
	
	for (int i = 0; i < A.size(); i++)
        if (A[i] != -1)
		    res[A[i]].push_back(i);
	
	return res;
}

int getRoot(vector<int> &A) {
	for (int i = 0; i < A.size(); i++)
		if (A[i] == -1)
			return i;	
	return 0;
}
