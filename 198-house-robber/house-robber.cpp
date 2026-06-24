class Solution {
public:

int maxAmount(vector<int>&nums,int i, vector<int>&dp){
    int prev1=nums[0];
    //edge case
    int prev2=0;
int curr;
    //main logic
    for(int t=0;t<nums.size(); t++){
     int rob=nums[t];
     if(t>1){
        rob+=prev2;


     }
    int notrob =0+prev1;
     curr=max(rob, notrob);
     prev2=prev1;
     prev1=curr;
    
}
return prev1;

    }



   
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return maxAmount(nums,0, dp);
    }
};