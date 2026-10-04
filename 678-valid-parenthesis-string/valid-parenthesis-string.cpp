class Solution {
public:
    bool checkValidString(string s) {


       int low=0;
       int high=0;

       for(char c:s){
        if(c=='('){
            low++;
            high++;
        }else if(c==')'){
            low--;
            high--;
        }else{
            low--;
            high++;
        }
        if(high<0){
            return 0;
        }
        low=max(low,0);
       }
       return low==0;
        
    }
};