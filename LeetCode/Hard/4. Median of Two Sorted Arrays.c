/*
Runtime: 16 ms, faster than 86.16% of C online submissions for Median of Two Sorted Arrays.
Memory Usage: 26 MB, less than 11.99% of C online submissions for Median of Two Sorted Arrays.
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if(nums1Size == 0 && nums2Size == 0)return 0;
    
    int* tmp = (int *)malloc(2000 * sizeof(int));

    int left1 = 0, left2 = 0;
    int count = 0;

    // 放到一半即可
    while (count < (nums1Size + nums2Size)/2 + 1)
    {
        if(left1 == nums1Size && left2 != nums2Size){
            tmp[count++] = nums2[left2];
            left2++;
            continue;
        }

        if(left2 == nums2Size && left1 != nums1Size){
            tmp[count++] = nums1[left1];
            left1++;
            continue;
        }

        if(nums1[left1] > nums2[left2])
        {
            tmp[count++] = nums2[left2];
            left2 ++;
        }
        else if(nums1[left1] < nums2[left2])
        {
            tmp[count++] = nums1[left1];
            left1 ++;
        }
        else
        {
            tmp[count++] = nums1[left1];
            tmp[count++] = nums2[left2];
            left1++;
            left2++;
        }
    }
    
    
    if((nums1Size + nums2Size) % 2 == 0)
    {
        // 中位數為 (nums1Size + nums2Size)/2 & (nums1Size + nums2Size)/2 - 1
        return ((double)tmp[(nums1Size + nums2Size)/2] + (double)tmp[(nums1Size + nums2Size)/2 - 1] ) / 2;
    }
    else
    {
        // 中位數為 (nums1Size + nums2Size)/2 
        return (double)tmp[(nums1Size + nums2Size)/2];
    }
}
