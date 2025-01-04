class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result=[[]]
        for n in nums:
            subsets=[]
            for current in result:
                temp=current.copy()
                temp.append(n)
                subsets.append(temp)
            for current in subsets:
                result.append(current)
        return result
