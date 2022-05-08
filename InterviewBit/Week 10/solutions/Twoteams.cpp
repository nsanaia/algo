#include <bits/stdc++.h>

unordered_map<int, vector<int>> getGraph(int A, vector<vector<int> > &B) {
    unordered_map<int, vector<int>>  res;
    while (A)
        res[A--] = {};
    
    for (auto& enemies : B) {
        int a = enemies[0], b = enemies[1];
        
        res[a].push_back(b);
        res[b].push_back(a);
    }

    return res;
}

int getEnemyTeam(int teamIdx) {
    return teamIdx == 1 ? 2 : 1;
}

bool isPossible(int curr, int currTeam, unordered_map<int, vector<int>>& graph, vector<int>& teams) {
    if (teams[curr] > 0)
        return teams[curr] == currTeam;
    
    teams[curr] = currTeam;

    for (auto enemy : graph[curr]) {
        if (!isPossible(enemy, getEnemyTeam(currTeam), graph, teams))
            return false;
    }

    return true;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    auto graph = getGraph(A, B);
    vector<int> teams(A + 1, 0);

    for (int i = 1; i <= A; i++) {
        if (teams[i] > 0)
            continue;
        if (!isPossible(i, 1, graph, teams))
            return 0;
    }

    return 1;
}
