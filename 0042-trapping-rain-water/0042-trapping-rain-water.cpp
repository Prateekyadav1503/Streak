class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        int lmax=0;
        int rmax=0;
        int i=0;
        int j=n-1;
        int ans=0;

        while(i<j){
        lmax=max(lmax,a[i]);
        rmax=max(rmax,a[j]);

        if(lmax<rmax){
            ans+=lmax-a[i];
            i++;}
        else{
            ans+=rmax-a[j];
            j--;}
        }
         return ans ;
    }
};