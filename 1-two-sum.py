from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap={}
        for i,num in enumerate(nums):
            sub=target-num
            if sub in hashmap:
                return [hashmap[sub],i]
            hashmap[num]=i
        return []
        
def process():
    print("Enter the string of numbers separated by spaces: ")
    nums_str=input()
    nums=[int(x) for x in nums_str.split()]
    print("Enter the target number: ")
    target=int(input())
    s=Solution()
    result=s.twoSum(nums, target)
    print(result)
    
if __name__ == '__main__':
    process()
