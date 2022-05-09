void seeAdjacents(int row, int col, vector<string>& board, vector<vector<bool>>& seen);
vector<pair<int, int>> getBlackNeighbours(int row, int col, vector<string>& board);

int Solution::black(vector<string> &A) {
    if (A.empty())
        return 0;

    int N = A.size();
    int M = A[0].length();
    vector<vector<bool>> seen(N, vector<bool>(M, false));
    int res = 0;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (A[r][c] == 'X' && !seen[r][c]) {
                seeAdjacents(r, c, A, seen);
                res++;
            }
        }
    }

    return res;
}


void seeAdjacents(int row, int col, vector<string>& board, vector<vector<bool>>& seen) {
    if (seen[row][col])
        return;

    seen[row][col] = true;

    auto neighbours = getBlackNeighbours(row, col, board);
    for (auto & neighbour : neighbours)
         seeAdjacents(neighbour.first, neighbour.second, board, seen);
 }

vector<pair<int, int>> getBlackNeighbours(int row, int col, vector<string>& board) {
    int N = board.size();
    int M = board[0].length();
    vector<pair<int, int>> res;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i * j != 0 || (i == 0 && j == 0))
                continue;
            
            int r = row + i;
            int c = col + j;

            if (r >= 0 && r < N
                 && c >= 0 && c < M
                 && board[r][c] == 'X')
                res.push_back(make_pair(r, c));
        }
    }

    return res;
}
