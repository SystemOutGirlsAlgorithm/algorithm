# 121. Best Time to Buy and Sell Stock
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        idx, diff = 0, 0
        for i in range(1, len(prices)):
            if prices[i] < prices[idx]:
                idx = i
            else:
                tmp_diff = prices[i] - prices[idx]
                diff = max(diff, tmp_diff)
        return diff
