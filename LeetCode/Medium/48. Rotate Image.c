/*
Runtime: 8 ms, faster than 24.81% of C online submissions for Rotate Image.
Memory Usage: 6.5 MB, less than 7.25% of C online submissions for Rotate Image.
*/
void swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    
    // 沿主對角線做反轉
    for(int i = 0;i < matrixSize ; i++){
        for(int j = i ; j < matrixSize ; j++){
            if(i == j)continue;
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }

    // 垂直軸反轉
    for(int i = 0 ; i < matrixSize ; i++){
        int left = 0, right = matrixSize - 1;

        while (left < right)
        {
            swap(&matrix[i][left], &matrix[i][right]);
            left++;
            right--;
        }
    }

    *matrixColSize = matrixSize;
}
