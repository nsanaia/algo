
const vector<vector<int>> NEIGHBORS{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


void markNotReachables(int row, int col, vector<vector<char> > &board);
vector<pair<int, int>> getNeighbors(int row, int col, vector<vector<char> > &board);


void Solution::solve(vector<vector<char> > &A) {
    if (A.empty() || A[0].empty())
        return;

    int N  = A.size();
    int M = A[0].size();

    for (int i = 0; i < N; i++) {
        if (A[i][0] == 'O')
            markNotReachables(i, 0, A);

        if (A[i][M - 1] == 'O')
            markNotReachables(i, M - 1, A);
    }

    for (int i = 0; i < M; i++) {
        if (A[0][i] == 'O')
            markNotReachables(0, i, A);

        if (A[N - 1][i] == 'O')
            markNotReachables(N - 1, i, A);
    }

    for (int r = 0; r < N; r ++) {
        for (int c = 0; c < M; c++) {
            A[r][c] = (A[r][c] == 'B') ? 'O' : 'X';
        }
    }
}

void markNotReachables(int row, int col, vector<vector<char> > &board) {
    if (board[row][col] == 'B' || board[row][col] == 'X')
        return;
    
    board[row][col] = 'B';

    auto neighbors = getNeighbors(row, col, board);

    for (auto neighbor : neighbors)
        markNotReachables(neighbor.first, neighbor.second, board);

}

vector<pair<int, int>> getNeighbors(int row, int col, vector<vector<char> > &board) {
    int N  = board.size();
    int M = board[0].size();
    vector<pair<int, int>> res;
    

    for (auto d : NEIGHBORS) {
        int r = row + d[0];
        int c = col + d[1];

        if (r >= 0 && r < N && c >= 0 && c < M)
            res.push_back(make_pair(r, c));

    }

    return res;
}

