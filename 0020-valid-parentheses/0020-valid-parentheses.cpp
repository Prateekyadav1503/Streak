class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            // 1. Check for opening brackets properly
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } 
            // 2. Use 'else' so closing bracket logic ONLY runs for closing brackets
            else {
                // If there's a closing bracket but stack is empty, it's invalid
                if (st.empty()) {
                    return false; 
                }
                
                // 3. Check for matching pairs
                if ((s[i] == ')' && st.top() == '(') || 
                    (s[i] == ']' && st.top() == '[') || 
                    (s[i] == '}' && st.top() == '{')) {
                    st.pop(); 
                } else {
                    return false; 
                }
            }
        }
        
        // If stack is empty at the end, all brackets were matched
        return st.empty();
    }
};