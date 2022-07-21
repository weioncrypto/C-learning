int maxSubArray(int* nums, int numsSize){
    int max = nums[0], tmp = 0;

    for(int i = 0; i < numsSize ; i++){
        tmp += nums[i];
        if(tmp > max)max = tmp;

        // tmp小於0為重新尋找能讓值變大的數
        if(tmp < 0)tmp = 0; 
    }

    return max;
}
