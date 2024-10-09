class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open_brackets = 0
        min_operations_required = 0
        for char in s:
            if char == '(':
                open_brackets+=1
            else:
                if open_brackets > 0:
                    open_brackets-=1
                else:
                    min_operations_required+=1
        return min_operations_required+open_brackets
    
def read_and_process():
    print("Enter the string to be validated. The string should contain only '(' and ')': ")
    s = input()
    if not set(s).issubset({'(', ')'}):
        print("The string should only contain '(' and ')'.")
    else:
        result = Solution().minAddToMakeValid(s)
        print(f"Minimum operations required to make {s} valid is {result}")

if __name__ == '__main__':
    read_and_process()
