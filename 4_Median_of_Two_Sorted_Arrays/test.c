int* mergeTwo(int* nums1, int* nums2, int nums1Size, int nums2Size) {
    int* ret = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    int i = 0;
    int j = 0;
    int index = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            ret[index++] = nums1[i++];
        }
        else {
            ret[index++] = nums2[j++];
        }
    }
    while (i < nums1Size) {
        ret[index++] = nums1[i++];
    }
    while (j < nums2Size) {
        ret[index++] = nums2[j++];
    }
    return ret;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* cur1 = nums1;
    int* cur2 = nums2;
    int* arr = mergeTwo(cur1, cur2, nums1Size, nums2Size);

    int index = (nums1Size + nums2Size) / 2;
    if ((nums1Size + nums2Size) % 2) {
        return (double)arr[index];
    }
    else {
        return (double)(arr[index] + arr[index - 1]) / 2;
    }
}