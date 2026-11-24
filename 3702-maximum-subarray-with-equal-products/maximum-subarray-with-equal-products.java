
class Solution {
    public int maxLength(int[] nums) {
        int n = nums.length;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long product = 1;
            long gcdValue = 0;
            long lcmValue = 1;

            for (int j = i; j < n; j++) {
                product *= nums[j];

                gcdValue = gcd(gcdValue, nums[j]);

                lcmValue = (lcmValue / gcd(lcmValue, nums[j])) * nums[j];

                if (product == gcdValue * lcmValue) {
                    ans = Math.max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}


