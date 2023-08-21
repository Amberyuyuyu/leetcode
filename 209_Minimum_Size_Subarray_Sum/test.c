class Solution(object) :
    def minSubArrayLen(self, target, nums) :
    """
    : type target : int
    : type nums : List[int]
    : rtype : int
    """
    n = len(nums)
    ans = n + 1
    s = 0
    left = 0
    for right, x in enumerate(nums) :
        s += x
        #     while s - nums[left] >= target:
#         s -= nums[left]
#         left += 1
#     if s >= target:
#         ans = min(ans, right - left + 1)
# return ans if ans <= n else 0
while s >= target:
ans = min(ans, right - left + 1)
s -= nums[left]
left += 1
return ans if ans <= n else 0
