class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        def dfs(i,j):
            if i>j:
                return 0
            if i==j:
                return 1
            if s[i]==s[j]:
                return dfs(i+1,j-1)+2
            return max(dfs(i,j-1),dfs(i+1,j))
        return dfs(0,n-1)