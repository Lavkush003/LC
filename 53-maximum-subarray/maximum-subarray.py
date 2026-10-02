class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        bestending=nums[0]
        ans=nums[0]
        for i in range(1, len(nums)):
            v1=bestending+nums[i]
            v2=nums[i]
            bestending=max(v1,v2)
            ans=max(bestending,ans)
        return ans
        
        