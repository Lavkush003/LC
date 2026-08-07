class Solution {
    public String removeOuterParentheses(String s) {
        
       
        StringBuilder res=new StringBuilder();
        int lev=0;
        for(char ch: s.toCharArray()){
            if(ch=='('){
                if(lev>0) res.append(ch);
                lev++;
            }else if(ch==')'){
                lev--;
                if(lev>0) res.append(ch);
            }
        }
        return res.toString();
    }
}