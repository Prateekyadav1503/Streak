class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        // 建立 ASCII 字符到数字的快速映射
        vector<int> roman(128);
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        
        // 遍历到倒数第二个字符
        for (int i = 0; i + 1 < s.length(); ++i) {
            // 如果当前字符的值小于右边相邻字符的值，说明是减法情况（如 IV、XL）
            if (roman[s[i]] < roman[s[i + 1]]) {
                ans -= roman[s[i]];
            } else {
                ans += roman[s[i]];
            }
        }
        
        // 最后一个字符必定是加上的
        return ans + roman[s.back()];
    }
};