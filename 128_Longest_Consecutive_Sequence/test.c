class Solution(object) :
    def longestConsecutive(self, nums) :
    """
    : type nums : List[int]
    : rtype : int
    """
    hash_set = set(nums)
    max_len = 0
    # hash_dict = dict()
    # max_len = 0
    # for num in nums :
# if num not in hash_dict:
#     left = hash_dict.get(num - 1, 0)
#     right = hash_dict.get(num + 1, 0)
#     cur_len = 1 + left + right
#     if(cur_len>max_len):
#         max_len = cur_len
#     hash_dict[num] = cur_len
#     hash_dict[num - left] = cur_len
#     hash_dict[num + right] = cur_len
for num in nums :
if num - 1 not in hash_set :
cur_num = num
cur_streak = 1
while cur_num + 1 in hash_set :
cur_num += 1
cur_streak += 1
max_len = max(max_len, cur_streak)
return max_len