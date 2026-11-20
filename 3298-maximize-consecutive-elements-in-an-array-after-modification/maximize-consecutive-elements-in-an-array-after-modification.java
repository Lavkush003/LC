
import java.util.*;

class Solution {
    public int maxSelectedElements(int[] nums) {
        Arrays.sort(nums);

        Map<Integer, Integer> dp = new HashMap<>();

        int ans = 0;

        for (int x : nums) {

            // Option 1: Keep current element unchanged
            int keep = dp.getOrDefault(x - 1, 0) + 1;

            // Option 2: Increase current element by 1
            int increase = dp.getOrDefault(x, 0) + 1;

            dp.put(x, Math.max(dp.getOrDefault(x, 0), keep));

            dp.put(x + 1,
                Math.max(dp.getOrDefault(x + 1, 0), increase));

            ans = Math.max(ans,
                Math.max(dp.get(x), dp.get(x + 1)));
        }

        return ans;
    }
}
