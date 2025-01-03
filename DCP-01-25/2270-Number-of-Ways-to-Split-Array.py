class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        total=sum(nums)
        leftsum=0
        splits=0
        for i in range (len(nums)-1):
            leftsum+=nums[i]
            if leftsum>=(total - leftsum):
                splits+=1
        return splits
        