class Solution {
public:
    int maxNumberOfBalloons(string s) {
        unordered_map<char,int>have;
        int n = s.size();
        for(int i=0;i<n;i++)
        have[s[i]]++;
        unordered_map<char,int>need;
        need['b']=1;
        need['a']=1;
        need['l']=2;
        need['o']=2;
        need['n']=1;
        int res=INT_MAX;
        for(auto i:need){
        char c=i.first;
        int fneed=i.second;
        int fhave=have[c];
        int times=fhave/fneed;
        res= min(times,res);
    }
    return res; 
    }
};