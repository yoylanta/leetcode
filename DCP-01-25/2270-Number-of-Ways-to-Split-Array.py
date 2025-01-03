class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        right=(sum(nums)+1)//2
        leftsum=0
        splits=0
        for i in range (len(nums)-1):
            leftsum+=nums[i]
            if leftsum>=right:
                splits+=1
        return splits
        