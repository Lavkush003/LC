class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int ans=Integer.MAX_VALUE;
        int n=nums.size();

        for(int len=l;len<=r;len++){
            int sum=0;
      

            for(int i=0;i<len;i++){
                sum+=nums.get(i);

            }
            if(sum>0){
                ans=Math.min(ans,sum);
            }

            for(int i=len;i<n;i++){
                sum+=nums.get(i);
                sum-=nums.get(i-len);
                if(sum>0){
                    ans=Math.min(ans,sum);
                }
            }

        }

        return ans==Integer.MAX_VALUE ? -1 :ans;

    }
}