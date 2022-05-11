#include <bits/stdc++.h>


struct Cell {
    int row;
    int col;
};

const vector<vector<int>> NEIGHBORS{{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {-1, -2}, {1, -2}};

bool equals(int r, int c, int r1, int c1);
vector<Cell> getNeighbors(int row, int col, int maxRow, int maxCol);
int knightHelper(int N, int M, int currRow, int currCol, int endRow, int endCol);


int Solution::knight(int A, int B, int C, int D, int E, int F) {
    return knightHelper(A, B, C, D, E, F);
}


bool equals(int r, int c, int r1, int c1) {
    return r == r1 && c == c1;
}

vector<Cell> getNeighbors(int row, int col, int maxRow, int maxCol) {
    vector<Cell> res;

    for (auto n : NEIGHBORS) {
        int r = row + n[0];
        int c = col + n[1];

        if (r > 0 && r <= maxRow && c > 0 && c <= maxCol)
            res.push_back(Cell{r, c});
    }

    return res;
}

int knightHelper(int N, int M, int currRow, int currCol, int endRow, int endCol) {
    queue<Cell> nodes;
    nodes.push(Cell{currRow, currCol});

    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));

    int level = 0;

    while (!nodes.empty()) {
        int nextLevelLen = nodes.size();

        for  (int i = 0; i < nextLevelLen; i++) {
            auto curr = nodes.front();
            nodes.pop();

            if (visited[curr.row][curr.col])
                continue;
            visited[curr.row][curr.col] = true;

            if (equals(curr.row, curr.col, endRow, endCol))
                return level;

            auto neighbors = getNeighbors(curr.row, curr.col, N, M);

            for (auto n : neighbors)
                nodes.push(n);
        }

        level++;
    }

    return -1;
}
