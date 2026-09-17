class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for (int num : nums)
        {
            mp[num]++;
        }

        //min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mh;

        for (auto [num, freq] : mp)
        {
            cout << num << freq << '\n';
            mh.push({freq, num});

            if (mh.size() > k)
            {
                mh.pop();
            }
        }

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(mh.top().second);
            mh.pop();
        }

        return ans;
    }
};
