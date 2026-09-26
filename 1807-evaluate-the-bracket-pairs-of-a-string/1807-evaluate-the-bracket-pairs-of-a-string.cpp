#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Build a lookup map from the knowledge list
        std::unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }

        string result = "";
        int n = s.length();
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                // Extract key between '(' and ')'
                int start = ++i;
                while (i < n && s[i] != ')') {
                    i++;
                }
                string key = s.substr(start, i - start);
                
                // Lookup key in dict
                auto it = dict.find(key);
                if (it != dict.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
                i++; // Move past ')'
            } else {
                result += s[i];
                i++;
            }
        }

        return result;
    }
};