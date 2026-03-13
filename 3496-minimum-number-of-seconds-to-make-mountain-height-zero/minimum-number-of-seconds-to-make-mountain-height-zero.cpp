class Solution {
public:
    
    bool canFinish(long long time, int mountainHeight, vector<int>& workerTimes){
        long long removed = 0;
        
        for(int t : workerTimes){
            long long val = (long long)time / t;
            long long k = (sqrt(1 + 8LL * val) - 1) / 2;
            
            removed += k;
            
            if(removed >= mountainHeight)
                return true;
        }
        
        return false;
    }
    
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long left = 0;
        long long right = 1e18;
        long long ans = right;
        
        while(left <= right){
            long long mid = left + (right - left) / 2;
            
            if(canFinish(mid, mountainHeight, workerTimes)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        return ans;
    }
};