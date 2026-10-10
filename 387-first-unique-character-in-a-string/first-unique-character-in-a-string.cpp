class Solution {
public:
    int firstUniqChar(string s) {
        
     int n=s.size();
     unordered_map<char,int>f;

     int i;
     for(i=0; i<n;i++){
        f[s[i]]++;
     }
     for(i=0;i<n;i++){
        if(f[s[i]]==1){
            return i;
        }
     }
       return -1; 
    }
};