int compare(const void* a, const void* b) {

    return *(int*)a > *(int*)b; 
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {    
    
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    
    int pos1 = 0, pos2 = 0; 
    int* result = malloc(sizeof(int)*nums1Size);
    *returnSize = 0;
    
    
    while (pos1 < nums1Size && pos2 < nums2Size) {
        if (nums1[pos1] < nums2[pos2])
            pos1++;
        else if (nums1[pos1] > nums2[pos2])
            pos2++;
        else {
            result[(*returnSize)++] = nums1[pos1];
            pos1++;
            pos2++;
        }
    }
    
    return result;
}
