class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //bucket sort approach?
        unordered_map<int,int> mp;

        for (const int & num : nums)
        {
            mp[num]++;
        }

        //bucket sort
        vector<vector<int>> bucket(nums.size() + 1);

        for (const auto & [num, freq] : mp)
        {
            bucket[freq].push_back(num);
        }

        vector<int> res;

        for (int i = nums.size(); i > 0; i--)
        {
            if (!bucket[i].empty())
            {
                for (const auto & entry : bucket[i])
                {
                    res.push_back(entry);

                    if (res.size() == k)
                    {
                        return res;
                    }
                }
            }
        }

        return res;
    }
};
