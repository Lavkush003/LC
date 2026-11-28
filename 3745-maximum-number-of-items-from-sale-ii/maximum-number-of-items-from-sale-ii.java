
import java.util.*;

class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;

        // Step 1: Find maximum factor and count frequencies
        int maxFactor = n;
        int[] freq = new int[maxFactor + 1];

        for (int[] item : items) {
            freq[item[0]]++;
        }

        // Step 2: Calculate free-item gain using multiples
        int[] gain = new int[maxFactor + 1];

        for (int f = 1; f <= maxFactor; f++) {
            for (int j = f; j <= maxFactor; j += f) {
                gain[f] += freq[j];
            }
            gain[f]--;
        }

        // Step 3: Sort by price
        Arrays.sort(items, (a, b) ->
            Integer.compare(a[1], b[1])
        );

        long remaining = budget;
        long answer = 0;
        int minPrice = items[0][1];

        // Step 4: Buy beneficial copies first
        for (int[] item : items) {
            int factor = item[0];
            int price = item[1];

            if (price > 2L * minPrice) {
                break;
            }

            if (gain[factor] <= 0) {
                continue;
            }

            long take = Math.min(
                (long) gain[factor],
                remaining / price
            );

            answer += 2L * take;
            remaining -= take * price;
        }

        // Step 5: Buy cheapest items with remaining budget
        answer += remaining / minPrice;

        return (int) answer;
    }
}
