class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<char,int>f;

              int res=0;
               bool odd=false;
        for(int i=0;i<n;i++){
        
            f[s[i]]++;
        }
           
           
            for(auto i:f){
                int val=i.second;
                if(val%2==0){
                    res+=val;
                }else{
                res+=val-1;
                odd=true;

                }
            }
           if(odd){
            res++;
           }
        
        return res;
        
    }
};