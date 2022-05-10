#include <bits/stdc++.h>

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
UndirectedGraphNode * cloneGraphHelper(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *>&  cache);

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
	unordered_map<int, UndirectedGraphNode *> cache;
	return cloneGraphHelper(node, cache);
}

UndirectedGraphNode * cloneGraphHelper(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *>&  cache) {
	if (node == NULL)
		return NULL;
	
	if (cache.find(node -> label) != cache.end())
		return cache[node -> label];
		
	UndirectedGraphNode* res = new UndirectedGraphNode(node -> label);
    cache[node -> label] = res;
	
	for (auto& neighbor : node -> neighbors)
		(res -> neighbors).push_back(cloneGraphHelper(neighbor, cache));
	
	return res;
}

