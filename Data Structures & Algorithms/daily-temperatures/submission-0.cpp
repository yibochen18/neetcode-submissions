class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.size() == 0) return {};

        vector<int> ans(temperatures.size(), 0);
        stack<int> st;

        for (int i = 0; i < temperatures.size(); i++) {
            //if temp at current day > temp of prev day (top of stack)
            //answer is the index of current day - index of top of stack
            // if smaller than top of stack then we just push onto the stack
            // can continuously pop from top of the stack until the temperature is no longer greater than a value or st is empty

            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                ans[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }

        return ans;
    }
};
