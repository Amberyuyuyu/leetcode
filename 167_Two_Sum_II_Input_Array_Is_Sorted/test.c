/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int s1 = 0;
    int s2 = numbersSize - 1;
    int* arr = (int*)malloc(sizeof(int*) * 2);
    *returnSize = 2;
    while (s1 < s2) {
        if (numbers[s1] + numbers[s2] > target) {
            s2--;
        }
        if (numbers[s1] + numbers[s2] < target) {
            s1++;
        }
        if (numbers[s1] + numbers[s2] == target) {
            arr[0] = s1 + 1;
            arr[1] = s2 + 1;
            break;
        }
    }
    return arr;
}