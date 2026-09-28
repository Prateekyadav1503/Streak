class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size();
        int maxend =a[0];
        int minend =a[0];
        int ans=a[0]; 
        for(int i=1;i<n;i++){
            int v1 =a[i];
            int v2 =maxend*a[i];   // positive 
            int v3 =minend*a[i];   // negative
            maxend=max(v1,max(v2,v3));
            minend=min(v1,min(v2,v3));
            ans=max(ans,max(maxend,minend));
        }
        return ans;
    }
};