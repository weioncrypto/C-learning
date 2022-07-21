/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Sort Colors.
Memory Usage: 6.2 MB, less than 22.87% of C online submissions for Sort Colors.
*/
void merge(int **nums, int l, int m, int r) {
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1],R[n2];

    // L1 和 L2 為左右矩陣
    for (i = 0; i < n1; i++)
        L[i] = (*nums)[l + i];
    for (j = 0; j < n2; j++)
        R[j] = (*nums)[m + 1 + j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    // 最後依序賦值回去
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            (*nums)[k] = L[i];
            i++;
        }
        else {
           (*nums)[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        (*nums)[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        (*nums)[k] = R[j];
        j++;
        k++;
    }    
}

void mergesort(int ** nums,int l,int r) {
    if(l < r) {
        int mid = l + (r - l) / 2;
        mergesort(&(*nums), l, mid);
        mergesort(&(*nums), mid + 1, r);
        merge(&(*nums), l, mid ,r);
    }
}
void sortColors(int* nums, int numsSize){
    mergesort(&nums, 0 , numsSize - 1);
}
