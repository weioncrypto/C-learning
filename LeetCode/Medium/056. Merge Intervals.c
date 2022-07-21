/*
Runtime: 54 ms, faster than 99.11% of C online submissions for Merge Intervals.
Memory Usage: 28.4 MB, less than 8.28% of C online submissions for Merge Intervals.
*/
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int _cmp(const void *a, const void *b)
{
    int **a1 = (int **)a;
    int **b1 = (int **)b;
    
    if (a1[0][0] != b1[0][0]) {
        return a1[0][0] - b1[0][0];
    } else {
        return a1[0][1] - b1[0][1];
    }
}
int** merge(int** intervals, int intervalsSize , int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    // 定義左右，若右區間小於下一值左區間則分配記憶體
    if(intervalsSize == 1)return intervals;
    qsort(intervals, intervalsSize, sizeof(intervals[0]), _cmp);
    int** ret = (int**)calloc(10000,sizeof(int*));
    
    int left = intervals[0][0], right = intervals[0][1], count = 0;
    
    for(int i = 0 ; i < intervalsSize - 1 ; i++)
    {
        if(right < intervals[i+1][0])
        {
            //分配記憶體
            ret[count] = (int*)realloc(ret[count],sizeof(int) * 2);
            ret[count][0] = left;
            ret[count][1] = right;
            left = intervals[i+1][0];
            right = intervals[i+1][1];
            count++;
        }
        else
        {
            // 有交集重新定義左右界
            left = MIN(left, intervals[i+1][0]);
            right = MAX(right, intervals[i+1][1]);
        }
    }
    ret[count] = (int*)realloc(ret[count],sizeof(int) * 2);
    ret[count][0] = left;
    ret[count][1] = right;
    count++;
    
    *intervalsColSize = 2;
    *returnSize = count;
    returnColumnSizes[0]=(int*)malloc((*returnSize)*sizeof(int));
    for(int i = 0 ; i < (*returnSize) ; i++)
        returnColumnSizes[0][i]=2;
    return ret;
}
