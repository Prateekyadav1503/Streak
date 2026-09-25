class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        int n= a.size();
        sort(a.begin(),a.end());
        int closestsum = a[0]+a[1]+a[2];
         for (int i = 0; i<n-2; i++){
            int left= i+1;
            int right = n-1;
            while(left<right){
                int currsum= a[i]+a[left]+a[right];
                
                if(abs(currsum-target)<abs(closestsum-target)){
                    closestsum= currsum;}
                

                if(currsum<target){
                    left++;
                } else {
                    right--;
                }  
            }
         }
           return closestsum;
    }
};