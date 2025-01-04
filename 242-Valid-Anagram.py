class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count=[0]*26
        for letter in s:
            count[ord(letter)-ord('a')]+=1
        for letter in t:
            count[ord(letter)-ord('a')]-=1
        for value in count:
            if value!=0:
                return False
        return True