class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> ret;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                ret.push_back(left);
                ret.push_back(right);
                break;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return ret;
    }
};