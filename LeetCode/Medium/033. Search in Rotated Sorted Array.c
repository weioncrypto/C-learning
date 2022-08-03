int search(int* nums, int numsSize, int target){
    if(target == nums[0])
        return 0;
    else if(target == nums[numsSize - 1])
        return numsSize - 1;
    else {
        for(int i = (numsSize % 2 == 0) ? numsSize/2 : (numsSize - 1)/2 + 1 ; i < numsSize ; i++)
            if(target == nums[i])
                return i;

        for(int i = (numsSize % 2 == 0) ? numsSize/2 : (numsSize - 1)/2 ; i > 0 ; i--)
            if(target == nums[i])
                return i;
    }
    return -1;
}



int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;
    while (left <= right)   
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;

        if(nums[mid] < nums[right]) {
            // 中間小於最右，右半邊有序，判斷新邊界
            if(nums[mid] < target && nums[right] >= target) left = mid + 1;
            else right = mid - 1;
        }
        else {
            // 左半邊有序
            if(nums[mid] > target && nums[left] <= target) right = mid - 1;
            else left = mid + 1;
        }
    }
    return -1;
}
