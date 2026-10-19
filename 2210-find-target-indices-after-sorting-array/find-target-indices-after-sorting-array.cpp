class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        int n=nums.size();
        sort(nums.begin(), nums.end());

        // for(int i=0;i<n;i++){
        //   for(int j=i+1;j<n;j++){
        //     if(nums[i]==target && nums[j]==target){
        //         return {i,j};
        //     }
        //   }
        //   if(nums[i]==target){
        //     return {i};
        //   }
        // }
        // return {};

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(nums[i]==target){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};