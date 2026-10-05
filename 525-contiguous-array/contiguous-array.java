class Solution {
    public int findMaxLength(int[] nums) {

        int n=nums.length;
        int zero=0;
        int one=0;

        Map<Integer,Integer>map=new HashMap<>();
        int res=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }else{
                one++;
            }
            int diff=zero-one;
            if(diff==0){
                res=Math.max(res,i+1);
                continue;
            }
            if(!map.containsKey(diff)){
                map.put(diff,i);
            }
            int idx=map.get(diff);
            int len=i-idx;
            res=Math.max(res,len);

        }
        return res;


        
    }
}