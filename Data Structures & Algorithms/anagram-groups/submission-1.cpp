class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};

        vector<vector<string>> ans;
        // sort each string
        //map anagram string to group
        unordered_map<string, vector<string>> ssArr;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            ssArr[str].push_back(strs[i]);
        }

        for (auto & [key, vec] : ssArr) {
            ans.push_back(vec);
        }
        return ans;
    }
};
