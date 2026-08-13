class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        int n =s.size();
        for (int i=0;i<n;i++){
        f[s[i]]++;}
        bool odd = false;
        int res=0;

        for(auto i:f){
            int val=i.second;
            if(val%2==0){
            res+=val;}
        else{
            res+=val-1;
            odd=true;
        }
        }
        if(odd){
            return res+1;
        }
        return res;
    }
};