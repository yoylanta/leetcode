class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res=defaultdict(list)
        for string in strs:
            key=\\.join(sorted(string))
            res[key].append(string)
        return list(res.values())

        