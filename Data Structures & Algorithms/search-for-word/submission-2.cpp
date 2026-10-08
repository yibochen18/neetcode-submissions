class Solution {
public:
    vector<pair<int,int>> direction = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    // Don't even need to start the search until we find the first letter
                    dfs(board, word, 0, {i,j}, found);
                    if (found) return true;
                }
            }
        }

        return found;
    }

    //backtracking problem
    //No reuse, can go in one of 4 directions

    void dfs(vector<vector<char>> &board, string &word, int curr_index, pair<int,int> start, bool &found) {
        if (found) return;

        if (curr_index == word.size()) {
            found = true;
            return;
        }

        auto [row, col] = start;

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return;
        if (board[row][col] != word[curr_index]) return;

        char temp = board[row][col];
        board[row][col] = '@'; //mark it in place so we can't reuse it

        //SANDWICH
        for (auto &[dr, dc] : direction) {
            dfs(board, word, curr_index + 1, {row + dr, col + dc}, found);
        }

        //UNDO
        board[row][col] = temp;
    }
};
