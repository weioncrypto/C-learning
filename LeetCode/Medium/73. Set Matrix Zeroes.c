/*
Runtime: 62 ms, faster than 56.28% of C online submissions for Set Matrix Zeroes.
Memory Usage: 19.1 MB, less than 22.95% of C online submissions for Set Matrix Zeroes.
*/
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int** tmp = (int*)calloc(40000, sizeof(int*)); // 標記為0位置
    int count = 0;
    for(int i = 0 ; i < matrixSize ; i++) {
        for(int j = 0 ; j < (*matrixColSize) ; j++) {
            if(matrix[i][j] == 0) {
                tmp[count] = calloc(2,sizeof(int));
                tmp[count][0] = i;
                tmp[count][1] = j;
                count++;
            }
        }
    }

    // 將直行橫行化為0
    for(int i = 0 ; i < count ; i++) {
        memset(matrix[tmp[i][0]], 0 , sizeof(int) * (*matrixColSize));

        for(int j = 0 ; j < matrixSize ; j++) {
            matrix[j][tmp[i][1]] = 0;
        }
    }
}
