class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector of vectors, for each new word check if it matches any of the current vectors
        // (check if all letters match and there are no extra letters, need to consider duplicates)
        // if yes then its a anagram and we add it to the vector, if not make a new entry

        vector<vector<string>> ans;
        vector<map<char, int>> wordMap;
        map<map<char,int>, int> indexMap; //definitely a better way to do this

        for (string str : strs)
        {
            map<char, int> charMap;
            for (char c : str)
            {
                charMap[c]++;
            }
            // does it match any of the maps in the current wordMap?
            auto it = find(wordMap.begin(), wordMap.end(), charMap);

            if (it != wordMap.end())
            {
                //it exists, add to solution in that vector.
                ans[indexMap[charMap]].push_back(str);
            }
            else
            {
                //doesn't exist, add string as standalone in answer vector
                indexMap[charMap] = ans.size();
                ans.push_back({str});
                wordMap.push_back(charMap);
            }
        }

        return ans;
    }
};
