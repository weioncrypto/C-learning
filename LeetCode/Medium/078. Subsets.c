/*
Runtime: 4 ms, faster than 94.06% of C online submissions for Subsets.
Memory Usage: 9.8 MB, less than 8.91% of C online submissions for Subsets.
*/
void dfs(int *nums, int **ret, int base[10], int n,int i, int count, int *idx, int **rc) {
    if(i == n)
        return;

    // 分三種: 存此值並繼續，不存此值繼續，分配記憶體存目前base
    // 不存此值繼續
    dfs(nums, ret, base, n, i + 1, count, idx, rc);

    // 存此值繼續
    base[count] = nums[i];
    dfs(nums, ret, base, n, i + 1, count + 1, idx, rc);
    
    // 存目前值
    ret[(*idx)] = calloc(count + 1,sizeof(int));
    memcpy(ret[(*idx)] , base, sizeof(int) * (count + 1));
    (*rc)[(*idx)] = count + 1;
    (*idx)++;
    return;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** ret = calloc(2000, sizeof(int*));
    (*returnColumnSizes) = (int *)malloc(2000*sizeof(int));

    /* 先存入空矩陣 */
    ret[0] = calloc(1,sizeof(int));
    ret[0] = NULL;
    *returnColumnSizes[0] = 0;
    
    int base[10];
    int idx = 1;  // count為個別矩陣元素個數，idx則為總矩陣數，i為第幾個遍歷(以index)
    dfs(nums, ret, base, numsSize, 0, 0, &idx, returnColumnSizes);

    *returnSize = idx;
    return ret;
}
