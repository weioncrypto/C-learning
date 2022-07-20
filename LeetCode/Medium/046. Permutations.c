void getPermute(int **ret, int *nums, int numsSize, int *rs,int *buff, int index, bool *flag) {
    if(index == numsSize) {
        ret[(*rs)] = (int *)calloc(numsSize,sizeof(int));
        memcpy(ret[(*rs)], buff, sizeof(int) * numsSize);
        (*rs)++;
        return;
    }

    for(int i = 0 ; i < numsSize ; i++) {
        if(flag[i] == false) {
            flag[i] = true;
            buff[index] = nums[i];
            getPermute(ret,nums,numsSize,rs,buff,index + 1,flag);
            flag[i] = false;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    int **ret = (int **)calloc(1024, sizeof(int *)); 
    int *buff = (int *)calloc(numsSize, sizeof(int));
    bool *flag = (bool *)calloc(numsSize, sizeof(bool));

    int rs = 0;

    getPermute(ret, nums, numsSize, &rs, buff, 0, flag);

    *returnSize = rs;
    
    (*returnColumnSizes) = calloc((*returnSize),sizeof(int*));
    for(int i = 0 ; i < (*returnSize) ; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    
    return ret;
}
