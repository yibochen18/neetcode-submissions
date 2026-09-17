class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++)
        {
            const vector<char> & row = board[i];
             
            for (int j = 0; j < 9; j++)
            {
                int col = j;
                int box = (i / 3) * 3 + (col / 3);
                
                if (row[col] == '.') continue;
                else
                {
                    //char will implicitly be converted to ASCII
                    if(!rows[i].insert(row[col]).second) return false;
                    if(!cols[j].insert(row[col]).second) return false;
                    if(!boxes[box].insert(row[col]).second) return false;
                }
            }
        }

        return true;
    }
};
