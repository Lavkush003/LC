class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();

        int i;
        int power=0;
        int nopower=arr[0];
        int res=arr[0];

        for(i=1;i<n;i++){
            int v1=arr[i];
            int v2=nopower+arr[i];
            int v3=power+arr[i];
            int v4=nopower;
           
            nopower=max(v1,v2);
            power=max(v3,v4);
             res=max(res,max(v3,v4));
             res = max(res, max(nopower, power));
        }
        return res;
        
    }
};