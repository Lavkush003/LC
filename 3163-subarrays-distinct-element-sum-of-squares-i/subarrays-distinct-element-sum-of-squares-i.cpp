class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
      int sum=0;
      int count=1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int count=0;
                for(int k=i;k<=j;k++){
                    bool dis=true;
                    for(int p=i;p<k;p++){
                        if(nums[p]==nums[k]){
                            dis=false;
                        }
                    }
                    if(dis){
                        count++;
                    }
                    
                    }
                    sum+=count*count;
                
                }
            }
        
        return sum;
        
    }
};