class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
         letters=set(s)
         res=0
         for letter in letters:
            i,j=s.index(letter),s.rindex(letter)
            between=set()
            for k in range(i+1,j):
                between.add(s[k])
            res+=len(between)
         return res

        