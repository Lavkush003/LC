class Solution {
public:
int digitsum(int num){
    int sum=0;
    while(num>0){
        sum+=num%10;
        num=num/10;
    }
    return sum;
}
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>arr;

        for(int i=0;i<n;i++){
            arr.push_back({digitsum(nums[i]),nums[i]});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int,int>pos;

        for(int i=0;i<n;i++){
            pos[nums[i]]=i;
        }

        int count=0;

        for(int i=0;i<n;i++){
            if(nums[i]!=arr[i].second){
                int j=pos[arr[i].second];
                pos[nums[i]]=j;
                pos[nums[j]]=i;
                swap(nums[i],nums[j]);
                count++;
            }
        }
        return count;


        
    }
};