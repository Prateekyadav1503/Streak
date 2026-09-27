class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int n=a.size();
        int low=0;
        int high=0;
        int res=INT_MAX;
        int sum =0;
        for (high=0;high<n;high++){
            sum+=a[high];
             while(sum>=target){
                int len =high-low+1;
                res=min(len,res);
                sum=sum-a[low];
                low++;
             }
        }
        return (res==INT_MAX) ? 0:res;
    }
};