// dfs method, but time limit exceed

void dfs(int *nums, int numsSize, bool* find,int count){
    if(count > numsSize - 1)
    {
        return;
    }
    else if(count == numsSize - 1)
    {
        *find = true;
    }
    else
    {
        int n = nums[count];

        while (n != 0)
        {
            dfs(nums, numsSize, find,count+n);
            n--;
        }
    }
    return;
}

bool canJump(int* nums, int numsSize){
    bool find = false;
    dfs(nums, numsSize, &find, 0);
    return find;
}



// greedy
bool canJump(int* nums, int numsSize) {
    int max = 0;
    for(int i = 0 ; i < numsSize - 1 ; i++)
    {
        max = ((i + nums[i]) > max) ? (i + nums[i]) : max;
        if(max < i + 1)return false;
    }
    return true;
}
