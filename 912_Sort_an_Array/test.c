/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // int GetMidIndex(int*nums, int left, int right){
 //     int mid = (left + right) >> 1;
 //     if(nums[left] < nums[mid]){
 //         if(nums[mid] < nums[right]){
 //             return mid;
 //         }else if(nums[left] > nums[right]){
 //             return left;
 //         }else{
 //             return right;
 //         }
 //     }else{
 //         if(nums[mid] > nums[right]){
 //             return mid;
 //         }else if(nums[right] > nums[left]){
 //             return left;
 //         }else{
 //             return right;
 //         }
 //     }
 // }
void Swap(int* p, int* q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
}
// void InsertSort(int* nums, int n){
//     for(int i=0; i<n-1; i++){
//         int end = i;
//         int tmp = nums[end+1];
//         while(end >=0){
//             if(nums[end] > tmp){
//                 nums[end+1] = nums[end];
//                 end--;
//             }else{
//                 break;
//             }
//         }
//         nums[end+1] = tmp;
//     }
// }
// int PartSort(int* nums, int left, int right){

//     int index = GetMidIndex(nums,left,right);
//     Swap(&nums[index],&nums[left]);
//     int pivot = left;
//     int keyi = nums[left];
//     while(left < right){
//         while(left < right && nums[right] >= keyi){
//             right--;
//         }
//         nums[pivot] = nums[right];
//         pivot = right;
//         while(left<right && nums[left] <= keyi){
//             left++;
//         }
//         nums[pivot] = nums[left];
//         pivot = left;
//     }
//     pivot = left;
//     nums[pivot] = keyi;
//     return pivot;
// }
// void QuickSort(int* nums, int left, int right){
//     if(left >= right){
//         return;
//     }
//     int pivot = PartSort(nums,left,right);
//     if(pivot-1-left > 10){
//        QuickSort(nums,left,pivot-1); 
//     }else{
//         InsertSort(nums+left,pivot-1-left+1);
//     }
//     if(right-(pivot+1)>10){
//         QuickSort(nums,pivot+1,right);
//     }else{
//         InsertSort(nums+pivot+1,right-(pivot+1)+1);
//     }
// }
void ShellSort(int* nums, int n) {
    int gap = n;
    while (gap > 1) {
        gap /= 2;
        for (int i = 0; i < n - gap; i++) {
            int end = i;
            int tmp = nums[end + gap];
            while (end >= 0) {
                if (nums[end] > tmp) {
                    nums[end + gap] = nums[end];
                    end -= gap;
                }
                else {
                    break;
                }
            }
            nums[end + gap] = tmp;
        }
    }
}
void _MergeSort(int* nums, int begin, int end, int* tmp) {
    if (begin >= end) {
        return;
    }
    int mid = (begin + end) >> 1;
    int begin1 = begin, end1 = mid;
    int begin2 = mid + 1, end2 = end;
    _MergeSort(nums, begin1, end1, tmp);
    _MergeSort(nums, begin2, end2, tmp);
    int i = begin;
    while (begin1 <= end1 && begin2 <= end2) {
        if (nums[begin1] <= nums[begin2]) {
            tmp[i++] = nums[begin1++];
        }
        else {
            tmp[i++] = nums[begin2++];
        }
    }
    while (begin1 <= end1) {
        tmp[i++] = nums[begin1++];
    }
    while (begin2 <= end2) {
        tmp[i++] = nums[begin2++];
    }
    for (int j = begin; j <= end; j++) {
        nums[j] = tmp[j];
    }
}
void MergeSort(int* nums, int n) {
    int* tmp = (int*)malloc(sizeof(int) * n);
    _MergeSort(nums, 0, n - 1, tmp);
    free(tmp);
}
int* sortArray(int* nums, int numsSize, int* returnSize) {
    ShellSort(nums, numsSize);
    *returnSize = numsSize;
    return nums;
}