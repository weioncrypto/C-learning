int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    *returnSize = matrixSize * (*matrixColSize);
    int* ret = calloc(*returnSize, sizeof(int));
    int count = 0, direction = 1, num;   // 1r, 2d, 3l, 4u
    int i = 0, j = 0, flag = 1;
    while (count < (*returnSize))
    {
        switch (direction)
        {
        case 1:
            if(j + 1 == (*matrixColSize)) {
                num = matrix[i][j];
                matrix[i][j] = -101;
                direction++;
                i++;
            }else if(matrix[i][j + 1] == -101) {
                num = matrix[i][j];
                matrix[i][j] = -101;
                direction++;
                i++;
            }
            else if(j < (*matrixColSize)) {
                num = matrix[i][j];
                matrix[i][j] = -101;
                j++;
            }
            break;
        case 2:
            if(i + 1 == matrixSize) {
                num = matrix[i][j];
                matrix[i][j] = -101;
                direction++;
                j--;               
            }else if(matrix[i+1][j] == -101){
                num = matrix[i][j];
                matrix[i][j] = -101;
                direction++;
                j--;
            }
            else if(i < (matrixSize)) {
                num = matrix[i][j];
                matrix[i][j] = -101;
                i++;
            }
            flag = 0;
            break;

        case 3:
            if(j == 0) {
                num = matrix[i][j];
                matrix[i][j] = -101;
                direction++;
                i--;
            } else if (matrix[i][j - 1] == -101) {
                num = matrix[i][j];
                matrix[i][j] = -101;
                direction++;
                i--;
            }
            else if(j >= 0) {
                num = matrix[i][j];
                matrix[i][j] = -101;
                j--;
            }
            break;

        case 4:
            if(matrix[i - 1][j] == -101) {
                num = matrix[i][j];
                matrix[i][j] = -101;
                direction++;
                j++;
            }
            else if(i >= 0) {
                num = matrix[i][j];
                matrix[i][j] = -101;
                i--;
            }
            break;
        }
        ret[count] = num;
        count++;
        if(direction == 5)direction = 1;
    }
    return ret;
}
