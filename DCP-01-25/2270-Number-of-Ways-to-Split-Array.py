class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        leftsum=0
        rightsum=sum(nums)
        splits=0
        for i in range (len(nums)-1):
            leftsum+=nums[i]
            rightsum-=nums[i]
            if leftsum>=rightsum:
                splits+=1
        return splits
        