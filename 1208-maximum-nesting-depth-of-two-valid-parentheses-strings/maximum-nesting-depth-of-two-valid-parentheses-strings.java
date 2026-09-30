class Solution {
    public int[] maxDepthAfterSplit(String seq) {
  int n=seq.length();
  int depth=0;
  int []answer= new int[n];

  for(int i=0;i<n;i++){
    if(seq.charAt(i)=='('){
        depth++;
        answer[i]=depth%2;

    }else{
        answer[i]=depth%2;
        depth--;
    }
  }
 return answer;
        
    }
}