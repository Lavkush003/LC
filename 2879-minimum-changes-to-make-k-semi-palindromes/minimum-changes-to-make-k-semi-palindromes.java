
import java.util.Arrays;

class Solution {
    public int minimumChanges(String s, int k) {
        int n = s.length();
        int INF = 1000000000;

        int[][] cost = new int[n][n];

        // Step 1: Precompute semi-palindrome conversion costs
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                cost[i][j] = INF;

                // Try every proper divisor
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    // Check each residue group
                    for (int r = 0; r < d; r++) {
                        int left = i + r;
                        int right = i + r
                                + ((len - 1 - r) / d) * d;

                        // Make each group a palindrome
                        while (left < right) {
                            if (s.charAt(left) != s.charAt(right)) {
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[i][j] = Math.min(cost[i][j], changes);
                }
            }
        }

        // Step 2: DP
        int[][] dp = new int[n + 1][k + 1];

        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], INF);
        }

        dp[0][0] = 0;

        // Step 3: Calculate minimum changes
        for (int i = 1; i <= n; i++) {
            for (int parts = 1; parts <= k; parts++) {

                for (int len = 2; len <= i; len++) {

                    if (dp[i - len][parts - 1] == INF) {
                        continue;
                    }

                    dp[i][parts] = Math.min(
                        dp[i][parts],
                        dp[i - len][parts - 1]
                            + cost[i - len][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
}
