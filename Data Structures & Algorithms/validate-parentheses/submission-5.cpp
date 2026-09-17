class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0)
        {
            return false;
        }

        stack<char> stk;
        unordered_map<char, char> bracketMap;
        bracketMap['('] = ')';
        bracketMap['{'] = '}';
        bracketMap['['] = ']';

        unordered_set<char> set = {')', '}', ']'};

        for (int i = 0; i < s.size(); i++)
        {
            if (set.count(s[i]) != 1)
            {
                stk.push(s[i]);
            }
            else
            {
                if (stk.size() == 0)
                {
                    return false;
                }
                int top = stk.top();
                if (bracketMap[top] != s[i])
                {
                    return false;
                }
                stk.pop();
            }
        }

        //if stack is empty return false
        if (stk.size() != 0)
        {
            return false;
        }

        return true;
    }
};
