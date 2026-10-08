class Solution {
public:
    vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
                else if (grid[i][j] == 1) fresh++;
            }
        }

        int min = 0;

        while (!q.empty() && fresh >0){
            // if we don't keep track of the current layer size, we cant accurately track minutes;
            int layerSize = q.size();
            min++;

            for (int i = layerSize; i > 0; i--) {
                auto [row, col] = q.front();
                q.pop();

                for (auto [dr, dc] : dir) {
                    //bound check
                    if (row + dr < 0 || row + dr >= grid.size() || col + dc < 0 || col + dc >= grid[0].size()) continue;

                    if (grid[row + dr][col + dc] == 1) {
                        q.push({row + dr, col +dc});
                        // Ur rotten now
                        grid[row + dr][col + dc] = 2;
                        fresh--;
                    }
                }
            }
        }

        return fresh == 0 ? min : -1;
    }
};
