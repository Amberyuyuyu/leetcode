MAPPING = ["", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"];
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        n = len(digits)
        if n==0:
            return []
        ans = []
        path = ['']*n
        def dfs(i):
            if i==n:
                ans.append(''.join(path))
                return
            for c in MAPPING[int(digits[i])]:
                path[i] = c
                dfs(i+1)
        dfs(0)
        return ans