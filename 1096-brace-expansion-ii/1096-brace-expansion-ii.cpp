#include <string>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<set<string>> stk;
        // Ops stack stores operators: ',' or '+' (implicit concatenation)
        vector<char> ops;

        auto concatenate = [](const set<string>& set1, const set<string>& set2) {
            set<string> res;
            for (const string& s1 : set1) {
                for (const string& s2 : set2) {
                    res.insert(s1 + s2);
                }
            }
            return res;
        };

        auto unionSets = [](set<string>& set1, const set<string>& set2) {
            set1.insert(set2.begin(), set2.end());
        };

        // Evaluates top operators until reaching a lower priority operator or '('
        auto evaluate = [&](char min_op = 0) {
            while (!ops.empty() && ops.back() != '(') {
                if (min_op == '+' && ops.back() == ',') {
                    break; // Concatenation '+' has higher precedence than ','
                }
                char op = ops.back();
                ops.pop_back();

                set<string> right = stk.back(); stk.pop_back();
                set<string> left = stk.back(); stk.pop_back();

                if (op == '+') {
                    stk.push_back(concatenate(left, right));
                } else if (op == ',') {
                    unionSets(left, right);
                    stk.push_back(left);
                }
            }
        };

        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];

            if (c == '{') {
                if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
                    evaluate('+');
                    ops.push_back('+');
                }
                ops.push_back('(');
            } else if (c == '}') {
                evaluate();
                ops.pop_back(); // Remove '('
            } else if (c == ',') {
                evaluate();
                ops.push_back(',');
            } else {
                // Lowercase letter
                if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
                    evaluate('+');
                    ops.push_back('+');
                }
                stk.push_back({string(1, c)});
            }
        }

        evaluate();

        set<string>& resultSet = stk.back();
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};