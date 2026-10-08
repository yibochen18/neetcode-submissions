class Solution {
public:
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, {i,j});
                    ans++;
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, pair<int, int> index) {
        //check bounds
        if (index.first < 0 || index.first >= grid.size() || index.second < 0 || index.second >= grid[0].size()) return;
        if (grid[index.first][index.second] != '1' || visited[index.first][index.second] == 1) return;

        //mark it as visited
        visited[index.first][index.second] = 1;

        //recurse :D
        for (auto [dr, dc] : directions) {
            dfs(grid, visited, {index.first + dr, index.second + dc});
        }

        return;
    }
};
