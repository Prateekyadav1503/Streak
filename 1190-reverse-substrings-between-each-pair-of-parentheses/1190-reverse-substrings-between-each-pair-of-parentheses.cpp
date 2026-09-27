#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<int> st;

        for (char c : s) {
            if (c == '(') {
                st.push(res.length());
            } else if (c == ')') {
                int start = st.top();
                st.pop();
                reverse(res.begin() + start, res.end());
            } else {
                res += c;
            }
        }

        return res;
    }
};