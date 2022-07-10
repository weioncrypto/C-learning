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
