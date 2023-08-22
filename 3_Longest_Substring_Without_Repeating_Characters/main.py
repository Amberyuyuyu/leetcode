class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        left = 0
        n = len(s)
        ans = 0
        cnt = Counter()
        for right,c in enumerate(s):
            cnt[c] += 1
            while(cnt[c] > 1):
                cnt[s[left]] -= 1
                left += 1
            ans = max(ans,right-left+1)
        return ans