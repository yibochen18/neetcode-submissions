class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0) return false;

        stack<char> stk;
        unordered_map<char, char> bracketMap;
        bracketMap[')'] = '(';
        bracketMap['}'] = '{';
        bracketMap[']'] = '[';

        for (int i = 0; i < s.length(); i++) {
            // if closing bracket is found
            if (bracketMap.count(s[i])) {
                //does it match what is at the top of the stack
                if (!stk.empty() && stk.top() == bracketMap[s[i]]) {
                    stk.pop();
                }
                else return false;
            }
            else {
                stk.push(s[i]);
            }
        }

        return stk.empty();
    }
};
