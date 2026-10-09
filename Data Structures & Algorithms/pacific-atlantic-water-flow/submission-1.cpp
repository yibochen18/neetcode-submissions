class Solution {
public:
    vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0, -1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // backtracking, from every spot, see if we can flow to both oceans (expensive though)
        //multi source bfs (instead of flow down from each node, flow up from the 2 oceans instead)

        if (heights.empty() || heights[0].empty()) return {};

        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> ans;

        //keep track of if we can reach the oceons
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        queue<pair<int,int>> qA, qP;
        
        for (int i = 0; i < row; i++) {
            pacific[i][0] = true;
            qP.push({i, 0});

            atlantic[i][col - 1] = true;
            qA.push({i, col - 1});
        }

        for (int j = 0; j < col; j++) {
            pacific[0][j] = true;
            qP.push({0,j});

            atlantic[row - 1][j] = true;
            qA.push({row - 1, j});
        }
        
        // bfs
        bfs(heights, qP, pacific);
        bfs(heights, qA, atlantic);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }

    void bfs(vector<vector<int>> &heights, queue<pair<int, int>> &q, vector<vector<bool>> &valid) {
        int rows = heights.size();
        int cols = heights[0].size();

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto &[dr, dc] : dir) {
                int newRow = row + dr;
                int newCol = col + dc;

                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;

                if (heights[newRow][newCol] >= heights[row][col] && !valid[newRow][newCol]) {
                    // water can reach here
                    valid[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }
};