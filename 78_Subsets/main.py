class Solution(object):
    def backtracking(self, nums, startIndex, path, result):
        result.append(path[:])
        for i in range(startIndex, len(nums)):
            path.append(nums[i])
            self.backtracking(nums, i + 1, path, result)
            path.pop()

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        path = []
        result = []
        self.backtracking(nums, 0, path, result)
        return result