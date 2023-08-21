class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        table = {}
        for str in strs:
            s = "".join(sorted(str))
            if(s in table.keys()):
                table[s].append(str)
            else:
                table[s] = [str]
        return list(table.values());
