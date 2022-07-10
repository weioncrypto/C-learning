/*
使用矩陣記下所有出現過的值
再遍歷矩陣抓出有交集的值
*/
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int temp_1[1005] = {0};
    int temp_2[1005] = {0};

    int count = 0;

    while (count < nums1Size || count < nums2Size)
    {
        if(count < nums1Size)temp_1[nums1[count]]++;
        if(count < nums2Size)temp_2[nums2[count]]++;
        count++;
    }


    int *ret = (int*)malloc(sizeof(int) * count);
    count = 0;
    for(int i=0;i<1005;i++){
        if(temp_1[i] != 0 && temp_2[i] != 0){
            ret = realloc(ret,sizeof(int)*(MIN(temp_1[i],temp_2[i])+count));
            for(int j=0;j<MIN(temp_1[i],temp_2[i]);j++){
                ret[count] = i;
                count++;
            }
        }
    }
    *returnSize = count;
    return ret;
}




/*
先將兩矩陣進行sort
再使用double pointer依次遍歷
若值相等則動態分配記憶體並儲存
*/
static int _cmp(void *a,void *b){
    return *(int *)a - *(int *)b;
}

#define MIN(a, b) ((a) < (b) ? (a) : (b))
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1,nums1Size,sizeof(int),_cmp);
    qsort(nums2,nums2Size,sizeof(int),_cmp);
    int p1 = 0, p2 = 0, count=0;
    int* ret = (int*)malloc(sizeof(int));

    while (p1 < nums1Size && p2 < nums2Size)
    {
        if(nums1[p1] == nums2[p2]){
            ret = realloc(ret,sizeof(int)*(count+1));
            ret[count] = nums1[p1];
            p1++;
            p2++;
            count++;
        }else if(nums1[p1] > nums2[p2]){
            p2++;
        }else p1++;
    }

    *returnSize = count;
    return ret;
    
}
