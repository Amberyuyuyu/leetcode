
int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0){
        return 0;
    }
    int slow = 0;
    int fast = 0;
    
    while (fast < numsSize) {
        if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}
