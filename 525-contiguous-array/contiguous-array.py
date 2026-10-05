class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        n=len(nums)
        zero=0
        one=0
        mp={}
        res=0

        for i in range(n):
            if nums[i]==0:
                zero+=1
            else:
                one+=1
            diff=zero-one

            if diff==0:
                res=max(res,i+1)
                continue
            
            if diff not in mp:
                mp[diff]=i
            
            idx=mp[diff]
            length=i-idx
            res=max(res,length)
        return res
        