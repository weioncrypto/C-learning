/*
- 先將矩陣由小至大進行 sort
- 遍歷矩陣，若該元素>0則搜尋結束
- 以第一個元素 i 為起始，後方集合使用left 和 right 夾擠配對
- 若 i 和上一個相同則跳過
- 若 left 和 right 和上一個相同也跳過
*/

static int _cmp(const int* a,const int* b){return (*a - *b);}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(numsSize * numsSize * sizeof(int));
    int** ret = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    qsort(nums,numsSize,sizeof(int),_cmp);

    for(int i=0 ; i < numsSize - 2 ; i++){
        if(i>0 && nums[i-1] == nums[i]) continue;
        int left = i + 1, right = numsSize - 1;
        while (left < right)
        {
            if(nums[i] > 0)break;
            if(nums[i] + nums[left] + nums[right] == 0){
                ret[*returnSize] = (int*)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[left];
                ret[*returnSize][2] = nums[right];
                *returnSize += 1;

                while (left < right && nums[left] == nums[left+1])
                {
                    left++;
                }

                while (left < right && nums[right] == nums[right - 1])
                {
                    right--;
                }
                
                left++;
                right--;

            }else if(nums[i] + nums[left] + nums[right] > 0)
                right--;
            else 
                left++;
        }
    }
    return ret;
}
