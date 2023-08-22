class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        m = len(s)
        n = len(p)
        ret = []
        if (m < n):
            return []

        s_cnt = [0] * 26
        p_cnt = [0] * 26
        for i in range(n):
            p_cnt[ord(p[i]) - ord('a')] += 1
            s_cnt[ord(s[i]) - ord('a')] += 1
        if p_cnt == s_cnt:
            ret.append(0)
        for i in range(m - n):
            s_cnt[ord(s[i]) - ord('a')] -= 1
            s_cnt[ord(s[i + n]) - ord('a')] += 1
            if s_cnt == p_cnt:
                ret.append(i + 1)
        return ret


