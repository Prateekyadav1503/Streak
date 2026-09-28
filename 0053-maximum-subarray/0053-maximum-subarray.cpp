class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n=a.size();
        int ans=a[0];
        int bestend=0;
        for(int i=0;i<n;i++){
            int v1 = bestend +a[i];
            int v2 = a[i];
            bestend=max(v1,v2);
            ans=max(ans,bestend);
        }
        return ans;
    }
};