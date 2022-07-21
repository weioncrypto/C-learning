/*
Runtime: 68 ms, faster than 97.66% of C online submissions for Longest Consecutive Sequence.
Memory Usage: 12.4 MB, less than 76.04% of C online submissions for Longest Consecutive Sequence.
*/
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static int _cmp(const int *l,const int *r){
    return (*l - *r);
}

int longestConsecutive(int* nums, int numsSize){
    if(numsSize == 0)return 0;

    qsort(nums, numsSize, sizeof(int), _cmp);

    int count = 1, max = 1;
    for(int i = 1 ; i < numsSize ; i++) {
        if(nums[i] == nums[i - 1])continue;
        if(nums[i] - nums[i - 1] == 1) {
            count++;
        } else {
            max = MAX(count, max);
            count = 1;
        }
    }
    
    max = MAX(count, max);
    return max;
}
