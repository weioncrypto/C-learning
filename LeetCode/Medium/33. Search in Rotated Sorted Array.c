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
