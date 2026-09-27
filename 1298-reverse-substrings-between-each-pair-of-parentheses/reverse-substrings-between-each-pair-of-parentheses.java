class Solution {
    public String reverseParentheses(String s) {

        StringBuilder current=new StringBuilder();

        Stack<String>stack=new Stack<>();

        for(char ch: s.toCharArray()){
            if(ch=='('){
                stack.push(current.toString());
                current.setLength(0);

            }else if(ch==')'){
                current.reverse();

                String previous=stack.pop();
                current.insert(0,previous);

            }else{
                current.append(ch);

            }
        }

        return current.toString();

        
    }
}