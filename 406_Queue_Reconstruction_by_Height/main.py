class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        people.sort(key=lambda x : (-x[0],x[1]))
        que = []
        for p in people:
            que.insert(p[1],p)
        return que
