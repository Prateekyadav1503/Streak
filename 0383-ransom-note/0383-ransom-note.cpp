class Solution {
public:
    bool canConstruct(string ransom, string magazine) {
        unordered_map<char,int>need;
        unordered_map<char,int>have;
        for(int i=0;i<ransom.size();i++){
        need[ransom[i]]++;}

         for(int i=0;i<magazine.size();i++){
        have[magazine[i]]++;}

            for(auto i:need)
            {char c=i.first;
            int fneed =i.second;
            int fhave=have[c];

            if(fhave<fneed){
            return false;
            }
         }
        return true ;
    }
};