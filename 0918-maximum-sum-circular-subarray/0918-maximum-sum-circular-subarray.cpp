class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        int n=a.size();
        int maxbestend =a[0];
        int minbestend =a[0];
        int res=a[0];
        int maxsum=a[0];
        int minsum=a[0];
        int totalsum=a[0];
        for (int i=1;i<n;i++)
        {
           totalsum += a[i];
         maxbestend=max(a[i],maxbestend+a[i]);
         minbestend=min(a[i],minbestend+a[i]);

         maxsum=max(maxsum,maxbestend);
         minsum=min(minsum,minbestend);}
           if(maxsum<0)return maxsum;{
           res=max(maxsum,totalsum-minsum);
        }
        return res;
    }
};