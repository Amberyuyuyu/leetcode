class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target >= letters[mid]) {
                left = mid + 1;
            }
            else if (target < letters[mid]) {
                right = mid;
            }
        }
        if (letters[left] > target) {
            return letters[left];
        }
        else {
            return letters[0];
        }
    }
};