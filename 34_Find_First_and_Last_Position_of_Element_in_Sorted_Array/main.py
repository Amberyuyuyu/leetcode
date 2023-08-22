def lower_bound(nums,target):
    left = 0
    right = len(nums)-1
    while left <= right:
        mid = left + (right-left)//2
        if nums[mid] < target:
            left = mid+1
        else:
            right = mid -1
    return left

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        start = lower_bound(nums, target)
        if start == len(nums) or nums[start] != target:
            return [-1,-1]
        end = lower_bound(nums,target+1)-1
        return [start,end]

