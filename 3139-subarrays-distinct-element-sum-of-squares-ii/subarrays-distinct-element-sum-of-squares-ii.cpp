// class Solution {
// public:
//     int sumCounts(vector<int>& nums) {
    //     int n=nums.size();
    //    int sum=0;
       
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             int count=0;
        
    //             for(int k=i;k<=j;k++){
    //                 bool dis=true;
    //                 for(int p=i;p<k;p++){

    //                     if(nums[p]==nums[k]){
    //                         dis=false;
    //                         break;
    //                     }
    //                 }
    //                 if(dis){
    //                     count++;
    //                 }
    //             }
    //             sum+=count*count;
    //         }
           
    //     }
    //     return sum;
        


        // int n=nums.size();

        // const int MOD=1e9+7;

        // long long sum=0;

        // for(int i=00;i<n;i++){
        //     vector<int>freq(100001,0);

        //     int count=0;
        //     for(int j=i;j<n;j++){
        //         if(freq[nums[j]]==0){
        //             count++;
        //         }
        //         freq[nums[j]]++;
        //         sum=(sum+1LL*count*count)%MOD;
        //     }
        // }
        // return sum;
//     }
// };



class Solution {
    static constexpr long long MOD = 1000000007;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        tree[node].sq = (
            tree[node].sq +
            2 * val * tree[node].sum +
            len * val * val
        ) % MOD;

        tree[node].sum = (
            tree[node].sum + len * val
        ) % MOD;

        tree[node].lazy += val;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long val = tree[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr) {

        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum = (
            tree[node * 2].sum +
            tree[node * 2 + 1].sum
        ) % MOD;

        tree[node].sq = (
            tree[node * 2].sq +
            tree[node * 2 + 1].sq
        ) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        tree.assign(4 * n + 5, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int prev = last[nums[j]];

            update(1, 0, n - 1, prev + 1, j);

            ans = (ans + tree[1].sq) % MOD;

            last[nums[j]] = j;
        }

        return (int)ans;
    }
};
