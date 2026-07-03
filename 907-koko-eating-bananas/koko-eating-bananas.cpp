class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l=1;
        int  high=*max_element(piles.begin(),piles.end());

        while(l<high){
            int mid=l+(high-l)/2;

            long long hours=0;
            for(int pile : piles){
                hours+=(pile+mid-1)/mid;
            }
            if(hours<=h)
                high=mid;
            else
            l=mid+1;
            
            
        }
        return l;
    }
};