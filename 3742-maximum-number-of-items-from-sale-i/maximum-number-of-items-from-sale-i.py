class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)

        dp = [0] * (budget + 1)
        cheapest = min(price for factor, price in items)

        for i in range(n):
            factor, price = items[i]

            free = 0
            for j in range(n):
                if i != j and items[j][0] % factor == 0:
                    free += 1

            for b in range(budget, price - 1, -1):
                dp[b] = max(dp[b], dp[b - price] + free + 1)

        ans = 0

        for b in range(budget + 1):
            ans = max(ans, dp[b] + (budget - b) // cheapest)

        return ans